#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Space Optimized Tabulation

/*
> Time Complexity: O()
> Space Complexity: O()
*/

class Solution
{
public:
    int frogJump(vector<int> &heights)
    {
        int n = heights.size();
        int prev = 0, prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            int oneStep = prev + abs(heights[i] - heights[i - 1]);

            int twoStep = INT_MAX;
            if (i > 1)
            {
                twoStep = prev2 + abs(heights[i] - heights[i - 2]);
            }

            prev2 = prev;
            prev = min(oneStep, twoStep);
            ;
        }
        return prev;
    }
};

//! Tabulation - Bottom Up

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int frogJump(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int oneStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);

            int twoStep = INT_MAX;
            if (i > 1)
            {
                twoStep = dp[i - 2] + abs(heights[i] - heights[i - 2]);
            }

            dp[i] = min(oneStep, twoStep);
        }
        return dp[n - 1];
    }
};

//!  Memoization

/*
> Time Complexity: O(N)
> Space Complexity: O(N) + O(N)
*/

class Solution
{
public:
    int helper(vector<int> &heights, int currStair, vector<int> &dp)
    {
        //* f(n-1): min energy required to reach (n-1) from 0
        if (currStair == 0)
        {
            return 0;
        }

        if (dp[currStair] != -1)
        {
            return dp[currStair];
        }

        int oneStep = helper(heights, currStair - 1, dp) + abs(heights[currStair] - heights[currStair - 1]);
        int twoStep = INT_MAX;
        if (currStair > 1)
        {
            twoStep = helper(heights, currStair - 2, dp) + abs(heights[currStair] - heights[currStair - 2]);
        }

        return dp[currStair] = min(oneStep, twoStep);
    }

    int frogJump(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> dp(n, -1);
        return helper(heights, n - 1, dp); //* we use 0 based indexing
    }
};

//! Recursion - Top Down Approach

/*
> Time Complexity: O(2^N)
> Space Complexity: O(N) + O(N) -> Recursion Stack Space + Array Used
*/

class Solution
{
public:
    int helper(vector<int> &heights, int currStair)
    {
        //* f(n-1): min energy required to reach (n-1) from 0
        if (currStair == 0)
        {
            return 0;
        }

        int oneStep = helper(heights, currStair - 1) + abs(heights[currStair] - heights[currStair - 1]);
        int twoStep = INT_MAX;
        if (currStair > 1)
        {
            twoStep = helper(heights, currStair - 2) + abs(heights[currStair] - heights[currStair - 2]);
        }

        return min(oneStep, twoStep);
    }

    int frogJump(vector<int> &heights)
    {
        int n = heights.size();
        return helper(heights, n - 1); //* we use 0 based indexing
    }
};