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
> Time Complexity: O(N)
> Space Complexity: O(6)
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> front1(2, 0);
        vector<int> front2(2, 0);
        vector<int> curr(2, 0);

        for (int currDay = prices.size() - 1; currDay >= 0; currDay--)
        {
            int buy = -prices[currDay] + front1[0];
            int notBuy = front1[1];
            curr[1] = max(buy, notBuy);

            int sell = prices[currDay] + front2[1];
            int notSell = front1[0];
            curr[0] = max(sell, notSell);

            front2 = front1;
            front1 = curr;
        }

        return front1[1];
    }
};

//-------------------------

/*
> Time Complexity: O(N * 2)
> Space Complexity: O(6)
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> front1(2, 0);
        vector<int> front2(2, 0);
        vector<int> curr(2, 0);

        for (int currDay = prices.size() - 1; currDay >= 0; currDay--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int profit = -1e9;
                if (canBuy)
                {
                    int buy = -prices[currDay] + front1[0];
                    int notBuy = front1[1];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[currDay] + front2[1];
                    int notSell = front1[0];
                    profit = max(sell, notSell);
                }
                curr[canBuy] = profit;
            }
            front2 = front1;
            front1 = curr;
        }

        return front1[1];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * 2)
> Space Complexity: O(N * 2)
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));

        for (int currDay = prices.size() - 1; currDay >= 0; currDay--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int profit = -1e9;
                if (canBuy)
                {
                    int buy = -prices[currDay] + dp[currDay + 1][0];
                    int notBuy = dp[currDay + 1][1];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[currDay] + (currDay + 2 < prices.size() ? dp[currDay + 2][1] : 0);
                    int notSell = dp[currDay + 1][0];
                    profit = max(sell, notSell);
                }
                dp[currDay][canBuy] = profit;
            }
        }

        return dp[0][1];
    }
};

//! Memoization DP
/*
> Time Complexity: O(N * 2)
> Space Complexity: O(N * 2) + O(N)
*/

class Solution
{
public:
    int helper(vector<int> &prices, int currDay, int canBuy, vector<vector<int>> &dp)
    {
        if (currDay >= prices.size())
        {
            return 0;
        }

        if (dp[currDay][canBuy] != -1)
        {
            return dp[currDay][canBuy];
        }

        int profit = -1e9;
        if (canBuy)
        {
            int buy = -prices[currDay] + helper(prices, currDay + 1, 0, dp);
            int notBuy = helper(prices, currDay + 1, 1, dp);
            profit = max(buy, notBuy);
        }
        else
        {
            int sell = prices[currDay] + helper(prices, currDay + 2, 1, dp);
            int notSell = helper(prices, currDay + 1, 0, dp);
            profit = max(sell, notSell);
        }
        return dp[currDay][canBuy] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return helper(prices, 0, 1, dp);
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(2^N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int helper(vector<int> &prices, int currDay, int canBuy)
    {
        if (currDay >= prices.size())
        {
            return 0;
        }

        int profit = -1e9;
        if (canBuy)
        {
            int buy = -prices[currDay] + helper(prices, currDay + 1, 0);
            int notBuy = helper(prices, currDay + 1, 1);
            profit = max(buy, notBuy);
        }
        else
        {
            int sell = prices[currDay] + helper(prices, currDay + 2, 1);
            int notSell = helper(prices, currDay + 1, 0);
            profit = max(sell, notSell);
        }
        return profit;
    }

    int maxProfit(vector<int> &prices)
    {

        return helper(prices, 0, 1);
    }
};