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
> Time Complexity: O(N * 2)
> Space Complexity: O(2)
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> front(2, 0);
        vector<int> curr(2, 0);

        for (int currDay = n - 1; currDay >= 0; currDay--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int profit = -1e9;
                if (canBuy)
                {
                    int buy = -prices[currDay] + front[0];
                    int notBuy = front[1];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[currDay] - fee + front[1];
                    int notSell = front[0];
                    profit = max(sell, notSell);
                }
                curr[canBuy] = profit;
            }
            front = curr;
        }

        return front[1];
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
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int currDay = n - 1; currDay >= 0; currDay--)
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
                    int sell = prices[currDay] - fee + dp[currDay + 1][1];
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
    int helper(vector<int> &arr, int fee, int currDay, int canBuy, vector<vector<int>> &dp)
    {
        if (currDay == arr.size())
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
            int buy = -arr[currDay] + helper(arr, fee, currDay + 1, 0, dp);
            int notBuy = helper(arr, fee, currDay + 1, 1, dp);
            profit = max(buy, notBuy);
        }
        else
        {
            int sell = arr[currDay] - fee + helper(arr, fee, currDay + 1, 1, dp);
            int notSell = helper(arr, fee, currDay + 1, 0, dp);
            profit = max(sell, notSell);
        }
        return dp[currDay][canBuy] = profit;
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return helper(prices, fee, 0, 1, dp);
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
    int helper(vector<int> &arr, int fee, int currDay, int canBuy)
    {
        if (currDay == arr.size())
        {
            return 0;
        }

        int profit = -1e9;
        if (canBuy)
        {
            int buy = -arr[currDay] + helper(arr, fee, currDay + 1, 0);
            int notBuy = helper(arr, fee, currDay + 1, 1);
            profit = max(buy, notBuy);
        }
        else
        {
            int sell = arr[currDay] - fee + helper(arr, fee, currDay + 1, 1);
            int notSell = helper(arr, fee, currDay + 1, 0);
            profit = max(sell, notSell);
        }
        return profit;
    }

    int stockBuySell(vector<int> arr, int n, int fee)
    {
        return helper(arr, fee, 0, 1);
    }
};
