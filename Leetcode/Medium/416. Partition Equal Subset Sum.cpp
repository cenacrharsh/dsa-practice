#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Space Optimized Tabulation DP

/*
> Time Complexity: O()
> Space Complexity: O()
*/

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * target)
> Space Complexity: O(N * target)
*/

class Solution
{
public:
    bool subsetSumEqualK(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        if (nums[0] <= target)
        {
            dp[0][nums[0]] = true;
        }

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int targetLeft = 1; targetLeft <= target; targetLeft++)
            {
                bool take = false;
                if (targetLeft >= nums[currIndex])
                {
                    take = dp[currIndex - 1][targetLeft - nums[currIndex]];
                }
                bool notTake = dp[currIndex - 1][targetLeft];

                dp[currIndex][targetLeft] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }

    bool canPartition(vector<int> &nums)
    {
        /*
            Sum of elements of S1 + sum of elements of S2 = sum of elements of S.
            Sum of elements of S1 = sum of elements of S2.
            These two conditions imply that S1 = S2 = (S/2).
            So all we need to do is find a subset with sum S/2, if yes then other subset is bound to have sum S/2 as well
        */

        int totalSum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            totalSum += nums[i];
        }
        if (totalSum % 2 != 0)
        {
            return false; //* odd sum can't be broken into 2 equal parts, if we skip this then DP might find floor(totalSum / 2) in the array and return true
        }
        int target = totalSum / 2;

        return subsetSumEqualK(nums, target);
    }
};

//! Memoization DP

/*
> Time Complexity: O()
> Space Complexity: O()
*/

//! Recursion -> Top Down Approach

/*
> Time Complexity: O()
> Space Complexity: O()
*/