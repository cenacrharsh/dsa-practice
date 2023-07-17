#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=fWX9xDmIzRI

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(N * Target)
> Space Complexity: O(Target)
*/

//* f(n-1, target) -> in the entire array from index 0->n-1 does there exist any target
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, false), curr(k + 1, false);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true; // wherever we have target == arr[0] we put true over there

    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool pick = false;
            if (target >= arr[index])
            {
                pick = prev[target - arr[index]];
            }

            bool notPick = prev[target];

            curr[target] = pick || notPick;
        }
        prev = curr;
    }
    return prev[k];
}

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * Target)
> Space Complexity: O(N * Target)
*/

//* f(n-1, target) -> in the entire array from index 0->n-1 does there exist any target
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true; // wherever we have target == arr[0] we put true over there

    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool pick = false;
            if (target >= arr[index])
            {
                pick = dp[index - 1][target - arr[index]];
            }

            bool notPick = dp[index - 1][target];

            dp[index][target] = pick || notPick;
        }
    }
    return dp[n - 1][k];
}

//! Memoization DP

/*
> Time Complexity: O(N * Target)
> Space Complexity: O(N * Target) + O(N) -> Recursive stack space
*/

//* f(n-1, target) -> in the entire array from index 0->n-1 does there exist any target

bool helper(int index, int target, vector<int> &arr,
            vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (index == 0)
        return arr[0] == target;

    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }

    bool pick = false;
    if (target >= arr[index])
    {
        pick = helper(index - 1, target - arr[index], arr, dp);
    }

    bool notPick = helper(index - 1, target, arr, dp);

    return dp[index][target] = pick || notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return helper(n - 1, k, arr, dp);
}

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(2^N)
> Space Complexity: O(N) -> Recursive stack space
*/

//* f(n-1, target) -> in the entire array from index 0->n-1 does there exist any target

bool helper(int index, int target, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (index == 0)
        return arr[0] == target;

    bool pick = false;
    if (target >= arr[index])
    {
        pick = helper(index - 1, target - arr[index], arr);
    }

    bool notPick = helper(index - 1, target, arr);

    return pick || notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return helper(n - 1, k, arr);
}