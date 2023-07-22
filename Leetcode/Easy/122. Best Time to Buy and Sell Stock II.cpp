#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=nGJmxkUJQGs&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=19

//- f(index, buy) -> f(0, 1) -> starting from day 1/index 0 with buy permission(1 buy, 0 not buy), what is the max profit we can generate

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(N * 2)
> Space Complexity: O(2 * 2)
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> next(2, 0), curr(2, 0);

        //* base case
        next[0] = next[1] = 0;

        for (int index = n - 1; index >= 0; index--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int profit = 0;
                if (canBuy)
                {
                    int buy = -prices[index] + next[0];
                    int notBuy = 0 + next[1];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[index] + next[1];
                    int notSell = 0 + next[0];
                    profit = max(sell, notSell);
                }
                curr[canBuy] = profit;
            }
            next = curr;
        }

        return next[1];
    }
};

//! Tabulation DP -> Top Down Approach

/*
> Time Complexity: O(N * 2)
> Space Complexity: O(N * 2)
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // base case
        dp[n][0] = dp[n][1] = 0;

        for (int index = n - 1; index >= 0; index--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int profit = 0;
                if (canBuy)
                {
                    int buy = -prices[index] + dp[index + 1][0];
                    int notBuy = 0 + dp[index + 1][1];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[index] + dp[index + 1][1];
                    int notSell = 0 + dp[index + 1][0];
                    profit = max(sell, notSell);
                }
                dp[index][canBuy] = profit;
            }
        }

        return dp[0][1];
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * 2)
> Space Complexity: O(N * 2) + O(N + 2)
*/

class Solution
{
public:
    int helper(int index, int canBuy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index == prices.size())
        {
            return false;
        }

        if (dp[index][canBuy] != -1)
        {
            return dp[index][canBuy];
        }

        if (canBuy)
        {
            int buy = -prices[index] + helper(index + 1, 0, prices, dp);
            int notBuy = 0 + helper(index + 1, 1, prices, dp);
            return dp[index][canBuy] = max(buy, notBuy);
        }
        else
        {
            int sell = prices[index] + helper(index + 1, 1, prices, dp);
            int notSell = 0 + helper(index + 1, 0, prices, dp);
            return dp[index][canBuy] = max(sell, notSell);
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, dp);
    }
};

//! Recursion -> Bottom Up Approach

/*
> Time Complexity: O(2^N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int helper(int index, int canBuy, vector<int> &prices)
    {
        if (index == prices.size())
        {
            return false;
        }

        if (canBuy)
        {
            int buy = -prices[index] + helper(index + 1, 0, prices);
            int notBuy = 0 + helper(index + 1, 1, prices);
            return max(buy, notBuy);
        }
        else
        {
            int sell = prices[index] + helper(index + 1, 1, prices);
            int notSell = 0 + helper(index + 1, 0, prices);
            return max(sell, notSell);
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        return helper(0, 1, prices);
    }
};