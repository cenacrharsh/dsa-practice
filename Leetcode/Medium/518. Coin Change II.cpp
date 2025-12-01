#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=HgyouUi11zk&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=11

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(N * T)
> Space Complexity: O(2T)
*/

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int N = coins.size();
        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);

        for (int amountLeft = 0; amountLeft <= amount; amountLeft++)
        {
            if (amountLeft % coins[0] == 0)
            {
                prev[amountLeft] = 1;
            }
            else
            {
                prev[amountLeft] = 0;
            }
        }

        for (int currIndex = 1; currIndex < N; currIndex++)
        {
            for (int amountLeft = 0; amountLeft <= amount; amountLeft++)
            {
                unsigned int notTake = prev[amountLeft];
                unsigned int take = 0;
                if (coins[currIndex] <= amountLeft)
                {
                    take = curr[amountLeft - coins[currIndex]];
                }

                curr[amountLeft] = take + notTake;
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
        int N = coins.size();
        vector<vector<int>> dp(N, vector<int>(amount + 1, 0));

        for (int amountLeft = 0; amountLeft <= amount; amountLeft++)
        {
            if (amountLeft % coins[0] == 0)
            {
                dp[0][amountLeft] = 1;
            }
            else
            {
                dp[0][amountLeft] = 0;
            }
        }

        for (int currIndex = 1; currIndex < N; currIndex++)
        {
            for (int amountLeft = 0; amountLeft <= amount; amountLeft++)
            {
                unsigned int notTake = dp[currIndex - 1][amountLeft];
                unsigned int take = 0;
                if (coins[currIndex] <= amountLeft)
                {
                    take = dp[currIndex][amountLeft - coins[currIndex]];
                }

                dp[currIndex][amountLeft] = take + notTake;
            }
        }

        return dp[N - 1][amount];
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * T)
> Space Complexity: O(N * T) + O(N)
*/

class Solution
{
public:
    int helper(vector<int> &coins, int currIndex, int amountLeft, vector<vector<int>> &dp)
    {
        if (currIndex == 0)
        {
            if (amountLeft % coins[currIndex] == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        if (dp[currIndex][amountLeft] != -1)
        {
            return dp[currIndex][amountLeft];
        }

        int notTake = helper(coins, currIndex - 1, amountLeft, dp);
        int take = 0;
        if (coins[currIndex] <= amountLeft)
        {
            take = helper(coins, currIndex, amountLeft - coins[currIndex], dp);
        }

        return dp[currIndex][amountLeft] = take + notTake;
    }

    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return helper(coins, coins.size() - 1, amount, dp);
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
    int helper(vector<int> &coins, int currIndex, int amountLeft)
    {
        if (currIndex == 0)
        {
            if (amountLeft % coins[currIndex] == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int notTake = helper(coins, currIndex - 1, amountLeft);
        int take = 0;
        if (coins[currIndex] <= amountLeft)
        {
            take = helper(coins, currIndex, amountLeft - coins[currIndex]);
        }

        return take + notTake;
    }

    int change(int amount, vector<int> &coins)
    {
        //* f(ind, target) -> till index ind, how many ways can you form target
        return helper(coins, coins.size() - 1, amount);
    }
};