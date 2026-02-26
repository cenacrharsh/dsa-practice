#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=D1oDwWCq50g&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=24

/*
> Time Complexity: O(log min(n1, n2))
> Space Complexity: O(1)
*/

int kthElement(vector<int> &arr1, vector<int> &arr2, int n1, int n2, int k)
{
    //> we'll apply the same concept as median of 2 sorted array, just while splitting instead of splitting n/2 n/2 (in case of even) n/2 + 1 n/2 (in case of odd)  we'll split k and n-k elements so that the last element of max(l1, l2 will be our kth element)

    if (n1 > n2)
    {
        return kthElement(arr2, arr1, n2, n1, k);
    }

    int low = max(0, k - n2); //* if k is smaller than n2 then fine we can take all elements form nums2 and 0 elements from nums2, but in case of k > n2, even after takikng all n2 elements from nums2 we are left with k - n2 elements which we have to take from nums1 so min value can't be 0, it has to max of (0, k - n2)

    int high = min(k, n1); //* at max we'll have k elements on left side so no need to go till n1 if n1 > k

    int left = k;

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
            return max(l1, l2);
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