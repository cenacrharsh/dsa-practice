#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=jtSiWTPLwd0&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=8

//! the index of the smallest element tells us the no. of times array has been rotated

int findKRotation(vector<int> &nums)
{
    //* sorted half may or maynot contain the answer -> pick the min from sorted half and eliminate it

    int low = 0, high = nums.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        //* if the entire search space is alredy sorted (i.e we have crossed the point of rotation) then nums[low] will always be the smallest element in that search space
        if (nums[low] <= nums[high])
        {
            if (nums[low] < ans)
            {
                ans = nums[low];
                index = low;
            }
            break;
        }

        //* left half is sorted
        if (nums[low] <= nums[mid])
        {
            //* pick the smallest element i.e arr[low] and eliminate
            if (nums[low] < ans)
            {
                ans = nums[low];
                index = low;
            }
            low = mid + 1;
        }
        //* right half is sorted
        else
        {
            //* pick the smallest element i.e arr[mid] and eliminate
            if (nums[mid] < ans)
            {
                ans = nums[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}
