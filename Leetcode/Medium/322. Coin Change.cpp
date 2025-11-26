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
> Time Complexity: O(N * Target)
> Space Complexity: O(Target)
*/

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        //* f(n - 1, amount): min coins required to form the target from 0->(n - 1)

        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);

        for (int amountLeft = 0; amountLeft <= amount; amountLeft++)
        {
            if (amountLeft % coins[0] == 0)
            {
                prev[amountLeft] = amountLeft / coins[0];
            }
            else
            {
                prev[amountLeft] = 1e9;
            }
        }

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int amountLeft = 0; amountLeft <= amount; amountLeft++)
            {
                int notTake = 0 + prev[amountLeft];
                int take = 1e9;
                if (coins[currIndex] <= amountLeft)
                {
                    take = 1 + curr[amountLeft - coins[currIndex]]; //* we don't decrease the currIndex becauese we have infinite supply so in take cases we won't change indexes as we can pick it up again
                }
                curr[amountLeft] = min(take, notTake);
            }
            prev = curr;
        }

        return prev[amount] == 1e9 ? -1 : prev[amount];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * Target)
> Space Complexity: O(N * Target)
*/

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        //* f(n - 1, amount): min coins required to form the target from 0->(n - 1)

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int amountLeft = 0; amountLeft <= amount; amountLeft++)
        {
            if (amountLeft % coins[0] == 0)
            {
                dp[0][amountLeft] = amountLeft / coins[0];
            }
            else
            {
                dp[0][amountLeft] = 1e9;
            }
        }

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int amountLeft = 0; amountLeft <= amount; amountLeft++)
            {
                int notTake = 0 + dp[currIndex - 1][amountLeft];
                int take = 1e9;
                if (coins[currIndex] <= amountLeft)
                {
                    take = 1 + dp[currIndex][amountLeft - coins[currIndex]]; //* we don't decrease the currIndex becauese we have infinite supply so in take cases we won't change indexes as we can pick it up again
                }
                dp[currIndex][amountLeft] = min(take, notTake);
            }
        }

        return dp[n - 1][amount] == 1e9 ? -1 : dp[n - 1][amount];
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * Target)
> Space Complexity: O(N * Target) + O(N)
*/

class Solution
{
public:
    int helper(vector<int> &coins, int currIndex, int amountLeft, vector<vector<int>> &dp)
    {
        //* now that we have reached the last index, we have to see whether we can achieve the target or not with the last coins
        if (currIndex == 0)
        {
            if (amountLeft % coins[0] == 0)
            {
                return amountLeft / coins[0];
            }
            else
            {
                return 1e9;
            }
        }

        if (dp[currIndex][amountLeft] != -1)
        {
            return dp[currIndex][amountLeft];
        }

        int notTake = 0 + helper(coins, currIndex - 1, amountLeft, dp);
        int take = 1e9;
        if (coins[currIndex] <= amountLeft)
        {
            take = 1 + helper(coins, currIndex, amountLeft - coins[currIndex], dp); //* we don't decrease the currIndex becauese we have infinite supply so in take cases we won't change indexes as we can pick it up again
        }
        return dp[currIndex][amountLeft] = min(take, notTake);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int minCount = helper(coins, n - 1, amount, dp);
        return minCount == 1e9 ? -1 : minCount;
    }
};

class Solution
{
public:
    int helper(vector<int> &coins, int currIndex, int amountLeft, vector<vector<int>> &dp)
    {
        //* now that we have reached the last index, we have to see whether we can achieve the target or not with the last coins
        if (currIndex == 0)
        {
            if (amountLeft % coins[0] == 0)
            {
                return amountLeft / coins[0];
            }
            else
            {
                return 1e9;
            }
        }

        if (dp[currIndex][amountLeft] != -1)
        {
            return dp[currIndex][amountLeft];
        }

        int notTake = 0 + helper(coins, currIndex - 1, amountLeft, dp);
        int take = 1e9;
        if (coins[currIndex] <= amountLeft)
        {
            take = 1 + helper(coins, currIndex, amountLeft - coins[currIndex], dp); //* we don't decrease the currIndex becauese we have infinite supply so in take cases we won't change indexes as we can pick it up again
        }
        return dp[currIndex][amountLeft] = min(take, notTake);
    }

    int MinimumCoins(vector<int> &coins, int amount)
    {
        //* f(n - 1, amount): min coins required to form the target from 0->(n - 1)

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int minCount = helper(coins, n - 1, amount, dp);
        return minCount == 1e9 ? -1 : minCount;
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(2^N) => much more that this, because in take cases we don't reduce indexes
> Space Complexity: O(N) => same here, recursion depth can go way higher
*/

class Solution
{
public:
    int helper(vector<int> &coins, int currIndex, int amountLeft)
    {
        //* now that we have reached the last index, we have to see whether we can achieve the target or not with the last coins
        if (currIndex == 0)
        {
            if (amountLeft % coins[0] == 0)
            {
                return amountLeft / coins[0];
            }
            else
            {
                return 1e9;
            }
        }

        int notTake = 0 + helper(coins, currIndex - 1, amountLeft);
        int take = 1e9;
        if (coins[currIndex] <= amountLeft)
        {
            take = 1 + helper(coins, currIndex, amountLeft - coins[currIndex]); //* we don't decrease the currIndex becauese we have infinite supply so in take cases we won't change indexes as we can pick it up again
        }
        return min(take, notTake);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int minCount = helper(coins, n - 1, amount);
        return minCount == 1e9 ? -1 : minCount;
    }
};