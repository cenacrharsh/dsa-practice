#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=GqOmJHQZivw&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=10

//* f(index, weight) -> what is the max value we can generate uptill index with a bag weight of weight

//! Space Optimized Tabulation DP

//# Right -> Left (One array optimization)

/*
> Time Complexity: O(N * M)
> Space Complexity: O(M)
*/



//# Left -> Right (Two array optimization)

/*
> Time Complexity: O(N * W)
> Space Complexity: O(2W)
*/

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);

    // base case => for every value of maxWeight >= weight[0] we can steal the 0th item
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        prev[i] = value[0];
    }

    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= maxWeight; wt++)
        {
            int pick = INT_MIN;
            if (wt >= weight[index])
            {
                pick = value[index] + prev[wt - weight[index]];
            }
            int notPick = 0 + prev[wt];

            curr[wt] = max(pick, notPick);
        }
        prev = curr;
    }
    return prev[maxWeight];
}

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * W)
> Space Complexity: O(N * W)
*/

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    // base case => for every value of maxWeight >= weight[0] we can steal the 0th item
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        dp[0][i] = value[0];
    }

    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= maxWeight; wt++)
        {
            int pick = INT_MIN;
            if (wt >= weight[index])
            {
                pick = value[index] + dp[index - 1][wt - weight[index]];
            }
            int notPick = 0 + dp[index - 1][wt];

            dp[index][wt] = max(pick, notPick);
        }
    }
    return dp[n - 1][maxWeight];
}

//! Memoization DP

/*
> Time Complexity: O(N * W)
> Space Complexity: O(N * W) + O(N) -> Recursive stack space
*/

#include <bits/stdc++.h>
int helper(int index, vector<int> weight, vector<int> value, int maxWeight, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (maxWeight >= weight[index])
        {
            return value[index];
        }
        else
        {
            return 0;
        }
    }

    if (dp[index][maxWeight] != -1)
    {
        return dp[index][maxWeight];
    }

    int pick = INT_MIN;
    if (maxWeight >= weight[index])
    {
        pick = value[index] + helper(index - 1, weight, value, maxWeight - weight[index], dp);
    }
    int notPick = 0 + helper(index - 1, weight, value, maxWeight, dp);

    return dp[index][maxWeight] = max(pick, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return helper(n - 1, weight, value, maxWeight, dp);
}

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(2^N)
> Space Complexity: O(N) -> Recursive stack space
*/

int helper(int index, vector<int> weight, vector<int> value, int maxWeight)
{
    if (index == 0)
    {
        if (maxWeight >= weight[index])
        {
            return value[index];
        }
        else
        {
            return 0;
        }
    }

    int pick = INT_MIN;
    if (maxWeight >= weight[index])
    {
        pick = value[index] + helper(index - 1, weight, value, maxWeight - weight[index]);
    }
    int notPick = 0 + helper(index - 1, weight, value, maxWeight);

    return max(pick, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return helper(n - 1, weight, value, maxWeight);
}