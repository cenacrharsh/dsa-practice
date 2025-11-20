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
> Time Complexity: O(N * W)
> Space Complexity: O(W)
*/

class Solution
{
public:
    int knapsack01(vector<int> &wt, vector<int> &val, int n, int W)
    {
        //* f(n - 1, W): max value we can achive by keeping weight under W from index 0->(n-1)

        vector<int> prev(W + 1, 0); //* we always need the previous guys while calculation of prev not current, so we can just use the prev one, also we need go from righ to left as rest of the array remains intact say for index i, 0->i - 1 is intact, then we update the value at i, in Left to Right we have already overwritten the prev elements

        for (int weightLeft = wt[0]; weightLeft <= W; weightLeft++)
        {
            prev[weightLeft] = val[0];
        }

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int weightLeft = W; weightLeft >= 0; weightLeft--)
            {
                int notTake = prev[weightLeft];
                int take = 0;
                if (wt[currIndex] <= weightLeft)
                {
                    take = val[currIndex] + prev[weightLeft - wt[currIndex]];
                }

                prev[weightLeft] = max(take, notTake);
            }
        }

        return prev[W];
    }
};

//-----------------------------------------------------------------------------------------

/*
> Time Complexity: O(N * W)
> Space Complexity: O(2W)
*/

class Solution
{
public:
    int knapsack01(vector<int> &wt, vector<int> &val, int n, int W)
    {
        //* f(n - 1, W): max value we can achive by keeping weight under W from index 0->(n-1)

        vector<int> prev(W + 1, 0);
        vector<int> curr(W + 1, 0);

        for (int weightLeft = wt[0]; weightLeft <= W; weightLeft++)
        {
            prev[weightLeft] = val[0];
        }

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int weightLeft = 0; weightLeft <= W; weightLeft++)
            {
                int notTake = prev[weightLeft];
                int take = 0;
                if (wt[currIndex] <= weightLeft)
                {
                    take = val[currIndex] + prev[weightLeft - wt[currIndex]];
                }

                curr[weightLeft] = max(take, notTake);
            }
            prev = curr;
        }

        return prev[W];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * W)
> Space Complexity: O(N * W)
*/

class Solution
{
public:
    int knapsack01(vector<int> &wt, vector<int> &val, int n, int W)
    {
        //* f(n - 1, W): max value we can achive by keeping weight under W from index 0->(n-1)

        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        for (int weightLeft = wt[0]; weightLeft <= W; weightLeft++)
        {
            dp[0][weightLeft] = val[0];
        }

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int weightLeft = 0; weightLeft <= W; weightLeft++)
            {
                int notTake = dp[currIndex - 1][weightLeft];
                int take = 0;
                if (wt[currIndex] <= weightLeft)
                {
                    take = val[currIndex] + dp[currIndex - 1][weightLeft - wt[currIndex]];
                }

                dp[currIndex][weightLeft] = max(take, notTake);
            }
        }

        return dp[n - 1][W];
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * W)
> Space Complexity: O(N * W) + O(N)
*/

class Solution
{
public:
    int helper(vector<int> &wt, vector<int> &val, int currIndex, int weightLeft, vector<vector<int>> &dp)
    {
        //* if there are no items left to pick or if there is no capacity left in the knapsack
        if (currIndex == 0)
        {
            if (wt[0] <= weightLeft)
            {
                return val[0];
            }
            else
            {
                return 0;
            }
        }

        if (dp[currIndex][weightLeft] != -1)
        {
            return dp[currIndex][weightLeft];
        }

        int notTake = helper(wt, val, currIndex - 1, weightLeft, dp);
        int take = 0;
        if (wt[currIndex] <= weightLeft)
        {
            take = val[currIndex] + helper(wt, val, currIndex - 1, weightLeft - wt[currIndex], dp);
        }

        return dp[currIndex][weightLeft] = max(take, notTake);
    }

    int knapsack01(vector<int> &wt, vector<int> &val, int n, int W)
    {
        //* f(n - 1, W): max value we can achive by keeping weight under W from index 0->(n-1)

        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return helper(wt, val, n - 1, W, dp);
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(2^N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int helper(vector<int> &wt, vector<int> &val, int currIndex, int weightLeft)
    {
        if (currIndex == 0)
        {
            if (wt[0] <= weightLeft)
            {
                return val[0];
            }
            else
            {
                return 0;
            }
        }

        int notTake = helper(wt, val, currIndex - 1, weightLeft);
        int take = 0;
        if (wt[currIndex] <= weightLeft)
        {
            take = val[currIndex] + helper(wt, val, currIndex - 1, weightLeft - wt[currIndex]);
        }

        return max(take, notTake);
    }

    int knapsack01(vector<int> &wt, vector<int> &val, int n, int W)
    {
        //* f(n - 1, W): max value we can achive by keeping weight under W from index 0->(n-1)

        return helper(wt, val, n - 1, W);
    }
};