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
> Time Complexity: O(N * TotalSum) + O(N) + O(N)
> Space Complexity: O(N * TotalSum)
*/

class Solution
{
public:
    int minDifference(vector<int> &arr, int n)
    {
        /*
            From the problem, subset sum == target, the DP array we generated
            for target i.e dp[n][target + 1] contains data for every possible
            value from [0->target] and whether it's possible or not
        */

        int totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            totalSum += arr[i];
        }
        int target = totalSum;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        if (arr[0] <= target)
        {
            dp[0][arr[0]] = true;
        }

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int targetLeft = 1; targetLeft <= target; targetLeft++)
            {
                bool take = false;
                if (targetLeft >= arr[currIndex])
                {
                    take = dp[currIndex - 1][targetLeft - arr[currIndex]];
                }
                bool notTake = dp[currIndex - 1][targetLeft];

                dp[currIndex][targetLeft] = take || notTake;
            }
        }

        //* Loop over dp array to find out the valid possible targets, we traverse only till totalSum/2 because after that they start repeating, for every s1 the s2 that we get is basically what we get for values of s1 after the totalSum/2 mark
        int minDiff = 1e9;
        for (int i = 0; i <= totalSum / 2; i++)
        {
            if (dp[n - 1][i] == true)
            {
                int subset1 = i;
                int subset2 = totalSum - i;
                minDiff = min(minDiff, abs(subset1 - subset2));
            }
        }
        return minDiff;
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
