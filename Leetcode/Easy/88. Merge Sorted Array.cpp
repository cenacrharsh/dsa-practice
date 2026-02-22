#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Without Extra Space + Gap Method of Shell Sort

//! Without Extra Space + 2 Pointers & Sorting

/*
> Time Complexity: O(min(N, M)) + O(N * Log N) + O(M * Log N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        //* target the largest element in nums1 and compare it with smallest element in nums2, if nums1 element is smaller than nums2 then swap and keep going until we find a element which is already in it's right place after which we don't need to look further as array are already sorted so rest would automatically be in the right place
        //* now correct elements are present in nums1 and nums2, just sort them since they are not in the right order

        int left = m - 1, right = 0;
        while (left >= 0 && right < n)
        {
            if (nums1[left] >= nums2[right])
            {
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            }
            else
            {
                break;
            }
        }

        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());

        right = 0;
        while (right < n)
        {
            nums1[m + right] = nums2[right];
            right++;
        }
    }
};

//! Without Extra Space + 2 Pointers => Works only if extra space is present in nums1

/*
> Time Complexity: O(M + N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int left = m - 1, right = n - 1;
        int index = m + n - 1;

        //* get the largest element and place it at the end, keep going till nums2 is finished, at that point nums1 will already have it's elements in order
        while (right >= 0)
        {
            if (left >= 0 && nums1[left] >= nums2[right])
            {
                nums1[index] = nums1[left];
                left--;
                index--;
            }
            else
            {
                nums1[index] = nums2[right];
                right--;
                index--;
            }
        }
    }
};

//! Using Extra Space

/*
> Time Complexity: O(N + M) + O(N + M) => Sort + Place in original array
> Space Complexity: O(N + M)
*/

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> merged(m + n);
        int left = 0, right = 0, index = 0;

        while (left < m && right < n)
        {
            if (nums1[left] <= nums2[right])
            {
                merged[index] = nums1[left];
                left++;
                index++;
            }
            else
            {
                merged[index] = nums2[right];
                right++;
                index++;
            }
        }

        while (left < m)
        {
            merged[index] = nums1[left];
            left++;
            index++;
        }
        while (right < n)
        {
            merged[index] = nums2[right];
            right++;
            index++;
        }

        for (int i = 0; i < m + n; i++)
        {
            nums1[i] = merged[i];
        }
    }
};