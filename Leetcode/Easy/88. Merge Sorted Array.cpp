#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=n7uwj04E0I4&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=39

//! Without Extra Space

//* compare the largest element in nums1 and smallest element in nums2, if largest element of nums1 is > smallest element of nums2 then we swap and move forward, once we find an element in nums1 and nums2 such that nums1 < nums2 we don't have to check any further since arr is sorted

class Solution
{
public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int left = n - 1;
        int right = 0;
        while (left >= 0 && right < m)
        {
            if (arr1[left] > arr2[right])
            {
                swap(arr1[left], arr2[right]);
                left--;
                right++;
            }
            else
            {
                break;
            }
        }

        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};

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