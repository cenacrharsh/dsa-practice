#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=HgyouUi11zk&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=11

//* f(ind, target) -> till index ind, how many ways can you form target

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(N * T)
> Space Complexity: O(2T)
*/

//* f(ind, target) -> till index ind, how many ways can you form target
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        for (int amt = 0; amt <= amount; amt++)
        {
            if (amt % coins[0] == 0)
            {
                prev[amt] = 1;
            }
        }

        for (int index = 1; index < n; index++)
        {
            for (int amt = 0; amt <= amount; amt++)
            {
                int take = 0;
                if (amt >= coins[index])
                {
                    take = curr[amt - coins[index]];
                }
                int notTake = prev[amt];

                curr[amt] = take + notTake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * T)
> Space Complexity: O(N * T)
*/

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int amt = 0; amt <= amount; amt++)
        {
            if (amt % coins[0] == 0)
            {
                dp[0][amt] = 1;
            }
        }

        for (int index = 1; index < n; index++)
        {
            for (int amt = 0; amt <= amount; amt++)
            {
                int take = 0;
                if (amt >= coins[index])
                {
                    take = dp[index][amt - coins[index]];
                }
                int notTake = dp[index - 1][amt];

                dp[index][amt] = take + notTake;
            }
        }
        return dp[n - 1][amount];
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * T)
> Space Complexity: O(N * T) + O(T)
*/

class Solution
{
public:
    int helper(int index, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (amount % coins[index] == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        if (dp[index][amount] != -1)
        {
            return dp[index][amount];
        }

        int take = 0;
        if (amount >= coins[index])
        {
            take = helper(index, amount - coins[index], coins, dp);
        }
        int notTake = helper(index - 1, amount, coins, dp);

        return dp[index][amount] = take + notTake;
    }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return helper(n - 1, amount, coins, dp);
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: >> O(2^N)
> Space Complexity: >> O(N)
*/

class Solution
{
public:
    int helper(int index, int amount, vector<int> &coins)
    {
        if (index == 0)
        {
            if (amount % coins[index] == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int take = 0;
        if (amount >= coins[index])
        {
            take = helper(index, amount - coins[index], coins);
        }
        int notTake = helper(index - 1, amount, coins);

        return take + notTake;
    }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        return helper(n - 1, amount, coins);
    }
};