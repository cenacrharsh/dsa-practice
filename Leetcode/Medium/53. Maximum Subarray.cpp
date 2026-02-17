#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Brute Force (Triple for loops to generate all subarrays)

//! Better (2 for loops and use prefix sum)

//! Optimal | Kadane's Algorithm

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currSum = 0, maxSum = INT_MIN;
        int startIndex = -1, endIndex = -1, currStart = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (currSum == 0)
            {
                currStart = i;
            }

            currSum += nums[i];

            if (currSum > maxSum)
            {
                maxSum = currSum;
                startIndex = currStart;
                endIndex = i;
            }

            //* a subarray with a sum less than 0 will always reduce the answer and so this type of subarray cannot be a part of the subarray with maximum sum
            if (currSum < 0)
            {
                currSum = 0;
            }
        }

        return maxSum;
    }
};