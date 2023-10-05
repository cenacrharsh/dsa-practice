#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=UvBKTVaG6U8&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=16

/*
> Time Complexity: O(log (max(arr) base 2)) * N
> Space Complexity: O(1)
*/

class Solution
{
public:
    int findMax(vector<int> &nums)
    {
        int maxElement = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            maxElement = max(maxElement, nums[i]);
        }
        return maxElement;
    }

    int calcSumOfDividends(vector<int> &nums, int threshold, int divisor)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += ceil((double)nums[i] / (double)divisor);

            if (sum > threshold)
            {
                return 0;
            }
        }
        return 1; //* sum <= threshold
    }

    //* low starts from not possible values and high starts from possible values
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        //* range lies b/w 1 and max(nums)

        //* min sum possible = size of array
        if (nums.size() > threshold)
        {
            return -1;
        }

        int low = 1, high = findMax(nums);
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int isPossible = calcSumOfDividends(nums, threshold, mid);
            if (isPossible == 1)
            {
                high = mid - 1; //* we want lowest possible value
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};