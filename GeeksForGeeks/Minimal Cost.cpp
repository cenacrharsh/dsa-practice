#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=Kmh3rhyEtB8&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=5

//! Space Optimized Tabulation DP

//* we would have to carry a list of size K to hold K previous values, and everytime we can just erase it's first element and add the curr element as the first element, but in worst case where K = N, we would have to hold N values so space complexity would still be O(N) so no need to optimize

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N) * K
> Space Complexity: O(N)
*/

int minimizeCost(vector<int> &height, int n, int k)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minEnergySpent = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            int currJumpEnergy = INT_MAX;
            if (i - j >= 0)
            {
                currJumpEnergy = dp[i - j] + abs(height[i] - height[i - j]);
            }
            minEnergySpent = min(minEnergySpent, currJumpEnergy);
        }
        dp[i] = minEnergySpent;
    }
    return dp[n - 1];
}

//! Memoization DP

/*
> Time Complexity: O(N) * K => where K is the number of jumps
> Space Complexity: O(N) + O(N)
*/

int helper(vector<int> &height, int index, int k, vector<int> &dp)
{
    if (index <= 0)
        return 0;

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int minEnergy = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        int currEnergySpent = INT_MAX;
        if (index - i >= 0)
        {
            currEnergySpent = helper(height, index - i, k, dp) + abs(height[index] - height[index - i]);
        }
        minEnergy = min(minEnergy, currEnergySpent);
    }

    return dp[index] = minEnergy;
}
int minimizeCost(vector<int> &height, int n, int k)
{
    vector<int> dp(n, -1);
    return helper(height, n - 1, k, dp);
}

//! Recursion -> Top Down Approach
int helper(vector<int> &height, int index, int k)
{
    if (index <= 0)
        return 0;

    int minEnergy = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        int currEnergySpent = INT_MAX;
        if (index - i >= 0)
        {
            currEnergySpent = helper(height, index - i, k) + abs(height[index] - height[index - i]);
        }
        minEnergy = min(minEnergy, currEnergySpent);
    }

    return minEnergy;
}
int minimizeCost(vector<int> &height, int n, int k)
{
    return helper(height, n - 1, k);
}