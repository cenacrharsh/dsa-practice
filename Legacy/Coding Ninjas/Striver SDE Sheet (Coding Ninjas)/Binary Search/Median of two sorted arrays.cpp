#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=C2rRzz-JDk8&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=23, https://www.youtube.com/watch?v=F9c7LpRZWVQ&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=23

//! Binary Search

/*
> Time Complexity: O(log (min(n1, n2)))
> Space Complexity: O(1)
*/

double median(vector<int> &arr1, vector<int> &arr2)
{
    //* valid symmetry - how many elements from arr1 and arr2 will be on left side and right side
    //* there will be only one valid symmetry

    int n1 = arr1.size();
    int n2 = arr2.size();
    if (n1 > n2)
    {
        return median(arr2, arr1); //* we want the first array to always be smaller
    }

    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1)
        {
            r1 = arr1[mid1];
        }
        if (mid2 < n2)
        {
            r2 = arr2[mid2];
        }

        if (mid1 - 1 >= 0)
        {
            l1 = arr1[mid1 - 1];
        }
        if (mid2 - 1 >= 0)
        {
            l2 = arr2[mid2 - 1];
        }

        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
            {
                return max(l1, l2);
            }
            return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
        {
            high = mid1 - 1; //* if we go right, that is more elements from arr1 hence elements larget than l1 hence we need to eliminate the right half
        }
        else
        {
            low = mid1 + 1; //* if we go left we'll get smaller elements from arr2 so we need to move right
        }
    }
    return 0;
}

//! No Extra Space

/*
> Time Complexity: O(n1 + n2)
> Space Complexity: O(1)
*/

double median(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n = n1 + n2;
    int index1 = (n / 2) - 1;
    int index2 = (n / 2);
    int element1 = -1;
    int element2 = -1;
    int i = 0, j = 0;
    int count = 0; //* index tracker, i.e. the index that we are lookin for in merged array
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            if (count == index1)
                element1 = arr1[i];
            if (count == index2)
                element2 = arr1[i];
            count++;
            i++;
        }
        else
        {
            if (count == index1)
                element1 = arr2[j];
            if (count == index2)
                element2 = arr2[j];
            count++;
            j++;
        }
    }
    while (i < n1)
    {
        if (count == index1)
            element1 = arr1[i];
        if (count == index2)
            element2 = arr2[i];
        count++;
        i++;
    }
    while (j < n2)
    {
        if (count == index1)
            element1 = arr1[j];
        if (count == index2)
            element2 = arr2[j];
        count++;
        j++;
    }

    if (n % 2 == 1)
    {
        return element2;
    }

    return (double)((double)(element1 + element2) / (2.0));
}

//! Using Extra Array

/*
> Time Complexity: O(n1 + n2)
> Space Complexity: O(n1 + n2)
*/

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        //* valid symmetry - how many elements from nums1 and nums2 will be on left side and right side
        //* there will be only one valid symmetry
        //* we're trying to figure out the left half, i.e how many elements on left from nums1 and nums2

        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2)
        {
            return findMedianSortedArrays(nums2, nums1); //* we want the first array to always be smaller for smaller time complexity
        }

        int low = 0, high = n1;       //* number of elements to be picked from nums1 for left side of the sorted combined array
        int left = (n1 + n2 + 1) / 2; //* number of elements on left side of sorted combined array, this formula works for both odd and even elements, (for odd elements we consider more elements of left side)
        int n = n1 + n2;
        while (low <= high)
        {
            int mid1 = (low + high) / 2; //* elements from nums1 on left side of sorted combined array
            int mid2 = left - mid1;      //* elements from nums2 on left side of sorted combined array

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            //* mid1 lies on r1 and mid2 lies on r2
            if (mid1 < n1)
            {
                r1 = nums1[mid1];
            }
            if (mid2 < n2)
            {
                r2 = nums2[mid2];
            }

            //* since mid1 lies on r1, mid1 - 1 becomes l1, mid2 lies on r2 so mid2 - 1 becomes l2
            if (mid1 - 1 >= 0)
            {
                l1 = nums1[mid1 - 1];
            }
            if (mid2 - 1 >= 0)
            {
                l2 = nums2[mid2 - 1];
            }

            //* nums1 and nums2 are individually already sorted so we compare across l1 to r2 and l2 to r1
            if (l1 <= r2 && l2 <= r1)
            {
                if (n % 2 == 1)
                {
                    return max(l1, l2);
                }

                //* in case of even numbers, the last/largest element from left half and first/smallest element of right half is taken, summed and divided by 2
                //* l1 -> largest from nums1 on left side, l2 -> largest from nums2 on left side
                //* r1 -> smallest from nums1 on right side, r2 -> smallest from nums2 on right side
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2)
            {
                high = mid1 - 1; //* if we go right, that is more elements from nums1 hence elements larger than l1 on left side and elements smaller than r2 on right side, hence we need to eliminate the right half
            }
            else
            {
                //* l2 > r1
                low = mid1 + 1; //* if we go left we'll get smaller elements from nums2 hence elements larger than l2 on left side and elements smaller than r2 on right side, so we need eliminate the left half
            }
        }
        return 0;
    }
};