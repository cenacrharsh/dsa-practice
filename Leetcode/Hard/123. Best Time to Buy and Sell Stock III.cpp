#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=-uQGzhYj8BQ&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=23

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(N * 2 * 3)
> Space Complexity: O(2 * 3)
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                for (int maxTransactions = 1; maxTransactions <= 2; maxTransactions++)
                {
                    if (canBuy == 1)
                    {
                        int buy = -prices[index] + next[0][maxTransactions];
                        int notBuy = 0 + next[1][maxTransactions];
                        curr[canBuy][maxTransactions] = max(buy, notBuy);
                    }
                    else
                    {
                        int sell = prices[index] + next[1][maxTransactions - 1];
                        int notSell = 0 + next[0][maxTransactions];
                        curr[canBuy][maxTransactions] = max(sell, notSell);
                    }
                }
            }
            next = curr;
        }

        return next[1][2]; // initial call we use in recursion f(0, 1, 2);
    }
};

//! Tabulation DP -> Top Down Approach

/*
> Time Complexity: O(N * 2 * 3)
> Space Complexity: O(N * 2 * 3)
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        /*
        // base case 1, maxTransactions == 0, i.e index and canBuy can have any value
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= 1; j++) {
                dp[i][j][0] = 0;
            }
        }
        // base case 2, index == n, i.e canBuy and maxTransactions can have any value
        for(int i = 0; i <= 1; i++) {
            for(int j = 0; j <= 2; j++) {
                dp[n][i][j] = 0;
            }
        }
        */

        for (int index = n - 1; index >= 0; index--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                for (int maxTransactions = 1; maxTransactions <= 2; maxTransactions++)
                {
                    if (canBuy == 1)
                    {
                        int buy = -prices[index] + dp[index + 1][0][maxTransactions];
                        int notBuy = 0 + dp[index + 1][1][maxTransactions];
                        dp[index][canBuy][maxTransactions] = max(buy, notBuy);
                    }
                    else
                    {
                        int sell = prices[index] + dp[index + 1][1][maxTransactions - 1];
                        int notSell = 0 + dp[index + 1][0][maxTransactions];
                        dp[index][canBuy][maxTransactions] = max(sell, notSell);
                    }
                }
            }
        }

        return dp[0][1][2]; // initial call we use in recursion f(0, 1, 2);
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * 2 * 3)
> Space Complexity: O(N * 2 * 3) + O(N)
*/

class Solution
{
public:
    int helper(int index, int canBuy, int maxTransactions, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (maxTransactions == 0)
            return 0;
        if (index == prices.size())
            return 0;

        if (dp[index][canBuy][maxTransactions] != -1)
        {
            return dp[index][canBuy][maxTransactions];
        }

        int profit = 0;
        if (canBuy)
        {
            int buy = -prices[index] + helper(index + 1, 0, maxTransactions, prices, dp);
            int notBuy = 0 + helper(index + 1, 1, maxTransactions, prices, dp);
            profit = max(buy, notBuy);
        }
        else
        {
            int sell = prices[index] + helper(index + 1, 1, maxTransactions - 1, prices, dp);
            int notSell = 0 + helper(index + 1, 0, maxTransactions, prices, dp);
            profit = max(sell, notSell);
        }

        return dp[index][canBuy][maxTransactions] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(0, 1, 2, prices, dp);
    }
};

//! Recursion -> Bottom Up Approach

/*
> Time Complexity: Exponential
> Space Complexity: O(N)
*/

class Solution
{
public:
    int helper(int index, int canBuy, int maxTransactions, vector<int> &prices)
    {
        if (maxTransactions == 0)
            return 0;
        if (index == prices.size())
            return 0;

        int profit = 0;
        if (canBuy)
        {
            int buy = -prices[index] + helper(index + 1, 0, maxTransactions, prices);
            int notBuy = 0 + helper(index + 1, 1, maxTransactions, prices);
            profit = max(buy, notBuy);
        }
        else
        {
            int sell = prices[index] + helper(index + 1, 1, maxTransactions - 1, prices);
            int notSell = 0 + helper(index + 1, 0, maxTransactions, prices);
            profit = max(sell, notSell);
        }

        return profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        return helper(0, 1, 2, prices);
    }
};