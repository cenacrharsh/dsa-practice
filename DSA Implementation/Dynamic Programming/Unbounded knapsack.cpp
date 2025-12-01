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
    int unboundedKnapsack(vector<int> &wt, vector<int> &val, int n, int W)
    {
        vector<int> curr(W + 1, 0);

        for (int weightLeft = 0; weightLeft <= W; weightLeft++)
        {
            curr[weightLeft] = ((int)(weightLeft / wt[0])) * val[0];
        }

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int weightLeft = 0; weightLeft <= W; weightLeft++)
            {
                int notTake = curr[weightLeft];
                int take = 0;
                if (wt[currIndex] <= weightLeft)
                {
                    take = val[currIndex] + curr[weightLeft - wt[currIndex]]; //* we always use some previous values from our curr array and one value from prev array, we can use one array for both, use prev values from curr array and currIndex value form curr array itself then after calculating it we can rewrite the value of currIndex
                }

                curr[weightLeft] = max(take, notTake);
            }
        }

        return curr[W];
    }
};

//----------------------––––––––––––––––––––-------------------------------------------------------------------------------

/*
> Time Complexity: O(N * W)
> Space Complexity: O(2W)
*/

class Solution
{
public:
    int unboundedKnapsack(vector<int> &wt, vector<int> &val, int n, int W)
    {
        vector<int> prev(W + 1, 0);
        vector<int> curr(W + 1, 0);

        for (int weightLeft = 0; weightLeft <= W; weightLeft++)
        {
            prev[weightLeft] = ((int)(weightLeft / wt[0])) * val[0];
        }

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int weightLeft = 0; weightLeft <= W; weightLeft++)
            {
                int notTake = prev[weightLeft];
                int take = 0;
                if (wt[currIndex] <= weightLeft)
                {
                    take = val[currIndex] + curr[weightLeft - wt[currIndex]];
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
    int unboundedKnapsack(vector<int> &wt, vector<int> &val, int n, int W)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        for (int weightLeft = 0; weightLeft <= W; weightLeft++)
        {
            dp[0][weightLeft] = (weightLeft / wt[0]) * val[0];
        }

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int weightLeft = 0; weightLeft <= W; weightLeft++)
            {
                int notTake = dp[currIndex - 1][weightLeft];
                int take = 0;
                if (wt[currIndex] <= weightLeft)
                {
                    take = val[currIndex] + dp[currIndex][weightLeft - wt[currIndex]];
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
> Space Complexity: O(W * W) + O(N)
*/

class Solution
{
public:
    int helper(vector<int> &wt, vector<int> &val, int currIndex, int weightLeft, vector<vector<int>> &dp)
    {
        if (currIndex == 0)
        {
            return (weightLeft / wt[currIndex]) * val[currIndex];
        }

        if (dp[currIndex][weightLeft] != -1)
        {
            return dp[currIndex][weightLeft];
        }

        int notTake = helper(wt, val, currIndex - 1, weightLeft, dp);
        int take = 0;
        if (wt[currIndex] <= weightLeft)
        {
            take = val[currIndex] + helper(wt, val, currIndex, weightLeft - wt[currIndex], dp);
        }

        return dp[currIndex][weightLeft] = max(take, notTake);
    }

    int unboundedKnapsack(vector<int> &wt, vector<int> &val, int n, int W)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return helper(wt, val, n - 1, W, dp);
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: >> O(2^N)
> Space Complexity: >> O(Naj)
*/

class Solution
{
public:
    int helper(vector<int> &wt, vector<int> &val, int currIndex, int weightLeft)
    {
        if (currIndex == 0)
        {
            return (weightLeft / wt[currIndex]) * val[currIndex];
        }

        int notTake = helper(wt, val, currIndex - 1, weightLeft);
        int take = 0;
        if (wt[currIndex] <= weightLeft)
        {
            take = val[currIndex] + helper(wt, val, currIndex, weightLeft - wt[currIndex]);
        }

        return max(take, notTake);
    }

    int unboundedKnapsack(vector<int> &wt, vector<int> &val, int n, int W)
    {

        return helper(wt, val, n - 1, W);
    }
};
