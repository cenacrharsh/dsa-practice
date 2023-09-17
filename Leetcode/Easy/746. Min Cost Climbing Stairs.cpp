#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Space Optimized Tabulation DP
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        //* We start at either step 0 or step 1. The target is to reach either last or second last step, whichever is minimum.
        int prev2 = cost[0];
        int prev = cost[1];
        for (int i = 2; i < cost.size(); i++)
        {
            int curr = cost[i] + min(prev, prev2);
            prev2 = prev;
            prev = curr;
        }
        return min(prev, prev2);
    }
};

//! Tabulation DP -> Bottom Up Approach
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        //* We start at either step 0 or step 1. The target is to reach either last or second last step, whichever is minimum.
        vector<int> dp(cost.size(), -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

//! Memoization DP
class Solution
{
public:
    int helper(vector<int> &cost, int step, vector<int> &dp)
    {
        if (step < 0)
        {
            return 0;
        };

        if (step == 0 || step == 1)
        {
            return cost[step];
        }

        if (dp[step] != -1)
        {
            return dp[step];
        }

        int oneStep = helper(cost, step - 1, dp);
        int twoStep = helper(cost, step - 2, dp);

        return dp[step] = cost[step] + min(oneStep, twoStep);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        //* We start at either step 0 or step 1. The target is to reach either last or second last step, whichever is minimum.
        vector<int> dp(cost.size(), -1);
        return min(helper(cost, cost.size() - 1, dp),
                   helper(cost, cost.size() - 2, dp));
    }
};

//! Recursion -> Top Down Approach
class Solution
{
public:
    int helper(vector<int> &cost, int step)
    {
        if (step < 0)
        {
            return 0;
        };

        if (step == 0 || step == 1)
        {
            return cost[step];
        }

        int oneStep = helper(cost, step - 1);
        int twoStep = helper(cost, step - 2);

        return cost[step] + min(oneStep, twoStep);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        //* We start at either step 0 or step 1. The target is to reach either last or second last step, whichever is minimum.
        return min(helper(cost, cost.size() - 1), helper(cost, cost.size() - 2));
    }
};

/* <-----------------------------------------------> */

//! Modifying given array
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        for (int i = 2; i < cost.size(); i++)
        {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};