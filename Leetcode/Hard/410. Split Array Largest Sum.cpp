#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=thUd_WJn6wk&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=20&t=14s

/*
> Time Complexity: O(log (sum - max) base 2) * O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int countSubarrays(vector<int> &nums, int maxSum)
    {
        int subarrays = 1;
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (totalSum + nums[i] > maxSum)
            {
                subarrays++;
                totalSum = nums[i];
            }
            else
            {
                totalSum += nums[i];
            }
        }
        return subarrays;
    }

    //* low starts from not possible values as we need to go higher to be able to split array into k parts, while high starts from possible values
    int splitArray(vector<int> &nums, int m)
    {
        //* min subarray sum has to be the largest element of the array
        //* max subarray sum has to be the sum of all elements

        //* if no of partitions required > size of array
        if (m > nums.size())
        {
            return -1;
        }

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int numOfSubarrays = countSubarrays(nums, mid);

            //* if no of subarrays is > m means we need to reduce the max sum allowed
            if (numOfSubarrays <= m)
            {
                high = mid - 1; //* as we want lowest possible value of max sum subarray
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};