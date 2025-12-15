#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=cKVl1TFdNXg&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=25

//! Space Optimized Tabulation DP

/*
> Time Complexity: O()
> Space Complexity: O()
*/

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N^2) + O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        //* we'll maintain a count vector along with dp vector, dp maintains the longest inc subs ending at index i but in count vector we'll maintain how many such subs we have ending at index i, so whenever a new count comes in dp array we'll inherit the initial count of that new subs but as the same length subs keep appearing we'll keep increasing the count for that particular length subs

        int n = nums.size();
        vector<int> dp(n, 1), count(n, 1);
        int maxLen = 1;

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    //* inherit the count of the this new length subs
                    count[i] = count[prev];
                }
                else if (nums[prev] < nums[i] && 1 + dp[prev] == dp[i])
                {
                    //* we encounter the same length subs so we inc the count
                    count[i] += count[prev];
                }
            }
            if (dp[i] > maxLen)
            {
                maxLen = dp[i];
            }
        }

        //* we'll calculate the sum total of of max length subs
        int noOfLis = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxLen)
            {
                noOfLis += count[i];
            }
        }
        return noOfLis;
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