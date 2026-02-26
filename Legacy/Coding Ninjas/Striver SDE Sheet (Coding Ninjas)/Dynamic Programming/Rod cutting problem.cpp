#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=mO8XpGoJwuo&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=12

//* try to pick lengths in such a way that they sum up to n and cost is maximized, we have an infinite supply of rod lenghts
//* f(ind, L) till index ind, what is the max price we can obtain while keeping len = L

//! Space Optimized Tabulation DP

// # 1 array

/*
> Time Complexity: O(N * N)
> Space Complexity: O(N)
*/

int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0);

    for (int len = 0; len <= n; len++)
    {
        prev[len] = len * price[0];
    }

    for (int index = 1; index < n; index++)
    {
        for (int len = 0; len <= n; len++)
        {
            int currRodLength = index + 1;

            int take = INT_MIN;
            if (len >= currRodLength)
            {
                take = price[index] + prev[len - currRodLength];
            }

            int notTake = prev[len];

            prev[len] = max(take, notTake);
        }
    }

    return prev[n];
}

// # 2 arrays

/*
> Time Complexity: O(N * N)
> Space Complexity: O(2N)
*/

int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int len = 0; len <= n; len++)
    {
        prev[len] = len * price[0];
    }

    for (int index = 1; index < n; index++)
    {
        for (int len = 0; len <= n; len++)
        {
            int currRodLength = index + 1;

            int take = INT_MIN;
            if (len >= currRodLength)
            {
                take = price[index] + curr[len - currRodLength];
            }

            int notTake = prev[len];

            curr[len] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[n];
}

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * N)
> Space Complexity: O(N * N)
*/

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int len = 0; len <= n; len++)
    {
        dp[0][len] = len * price[0];
    }

    for (int index = 1; index < n; index++)
    {
        for (int len = 0; len <= n; len++)
        {
            int currRodLength = index + 1;

            int take = INT_MIN;
            if (len >= currRodLength)
            {
                take = price[index] + dp[index][len - currRodLength];
            }

            int notTake = dp[index - 1][len];

            dp[index][len] = max(take, notTake);
        }
    }

    return dp[n - 1][n];
}

//! Memoization DP

/*
> Time Complexity: O(N * N)
> Space Complexity: O(N * N) + O(target)
*/

int helper(int index, int remainingLength, vector<int> &price, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        //* at the end we are left with a rod of length 1
        return remainingLength * price[0];
    }

    if (dp[index][remainingLength] != -1)
    {
        return dp[index][remainingLength];
    }

    int currRodLength = index + 1;

    int take = INT_MIN;
    if (remainingLength >= currRodLength)
    {
        take = price[index] + helper(index, remainingLength - currRodLength, price, dp);
    }

    int notTake = helper(index - 1, remainingLength, price, dp);

    return dp[index][remainingLength] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return helper(n - 1, n, price, dp);
}

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(exponential)
> Space Complexity: O(target)
*/

int helper(int index, int remainingLength, vector<int> &price)
{
    if (index == 0)
    {
        //* at the end we are left with a rod of length 1
        return remainingLength * price[0];
    }

    int currRodLength = index + 1;

    int take = INT_MIN;
    if (remainingLength >= currRodLength)
    {
        take = price[index] + helper(index, remainingLength - currRodLength, price);
    }

    int notTake = helper(index - 1, remainingLength, price);

    return max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
    return helper(n - 1, n, price);
}
