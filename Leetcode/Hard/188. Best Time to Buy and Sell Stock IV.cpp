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
> Time Complexity: O(N * 2 * K)
> Space Complexity: O(2 * K)
*/

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        //* we'll use transaction number instead of 2 variables canBuy and transactionsLeft
        vector<int> front((2 * k) + 1, 0);
        vector<int> curr((2 * k) + 1, 0);

        for (int currDay = prices.size() - 1; currDay >= 0; currDay--)
        {
            for (int transactionCount = 0; transactionCount < 2 * k; transactionCount++)
            {
                int profit = -1e9;
                if (transactionCount % 2 == 0)
                {
                    int buy = -prices[currDay] + front[transactionCount + 1];
                    int notBuy = front[transactionCount];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[currDay] + front[transactionCount + 1];
                    int notSell = front[transactionCount];
                    profit = max(sell, notSell);
                }
                curr[transactionCount] = profit;
            }
            front = curr;
        }
        return front[0];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * K * 2)
> Space Complexity: O(N * K * 2)
*/

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        //* we'll use transaction number instead of 2 variables canBuy and transactionsLeft
        vector<vector<int>> dp(prices.size() + 1, vector<int>((2 * k) + 1, 0));

        for (int currDay = prices.size() - 1; currDay >= 0; currDay--)
        {
            for (int transactionCount = 0; transactionCount < 2 * k; transactionCount++)
            {
                int profit = -1e9;
                if (transactionCount % 2 == 0)
                {
                    int buy = -prices[currDay] + dp[currDay + 1][transactionCount + 1];
                    int notBuy = dp[currDay + 1][transactionCount];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[currDay] + dp[currDay + 1][transactionCount + 1];
                    int notSell = dp[currDay + 1][transactionCount];
                    profit = max(sell, notSell);
                }
                dp[currDay][transactionCount] = profit;
            }
        }

        return dp[0][0];
    }
};

//! Memoization DP
/*
> Time Complexity: O(N * K * 2)
> Space Complexity: O(N * K * 2) + O(N)
*/

class Solution
{
public:
    int helper(vector<int> &prices, int k, int currDay, int transactionCount, vector<vector<int>> &dp)
    {
        //* for every successfull transaction we have 1 buy and 1 sell, hence overall 2 * k operations will be performed
        if (currDay == prices.size() || transactionCount == 2 * k)
        {
            return 0;
        }

        if (dp[currDay][transactionCount] != -1)
        {
            return dp[currDay][transactionCount];
        }

        //* even transactionCount indicates a buy-sell has been completed so we can buy again
        int profit = -1e9;
        if (transactionCount % 2 == 0)
        {
            int buy = -prices[currDay] + helper(prices, k, currDay + 1, transactionCount + 1, dp);
            int notBuy = helper(prices, k, currDay + 1, transactionCount, dp);
            profit = max(buy, notBuy);
        }
        else
        {
            int sell = prices[currDay] + helper(prices, k, currDay + 1, transactionCount + 1, dp);
            int notSell = helper(prices, k, currDay + 1, transactionCount, dp);
            profit = max(sell, notSell);
        }
        return dp[currDay][transactionCount] = profit;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        //* we'll use transaction number instead of 2 variables canBuy and transactionsLeft
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k, -1));
        return helper(prices, k, 0, 0, dp);
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
    int helper(vector<int> &prices, int k, int currDay, int transactionCount)
    {
        //* for every successfull transaction we have 1 buy and 1 sell, hence overall 2 * k operations will be performed
        if (currDay == prices.size() || transactionCount == 2 * k)
        {
            return 0;
        }

        //* even transactionCount indicates a buy-sell has been completed so we can buy again
        int profit = -1e9;
        if (transactionCount % 2 == 0)
        {
            int buy = -prices[currDay] + helper(prices, k, currDay + 1, transactionCount + 1);
            int notBuy = helper(prices, k, currDay + 1, transactionCount);
            profit = max(buy, notBuy);
        }
        else
        {
            int sell = prices[currDay] + helper(prices, k, currDay + 1, transactionCount + 1);
            int notSell = helper(prices, k, currDay + 1, transactionCount);
            profit = max(sell, notSell);
        }
        return profit;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        //* we'll use transaction number instead of 2 variables canBuy and transactionsLeft
        return helper(prices, k, 0, 0);
    }
};

//------------------------------------------------------------------------------------------------------//

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(N * 2 * K)
> Space Complexity: O(2 * K)
*/

class Solution
{
public:
    int stockBuySell(vector<int> arr, int n, int k)
    {
        vector<vector<int>> front(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));

        for (int currDay = n - 1; currDay >= 0; currDay--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                for (int transactionsLeft = 1; transactionsLeft <= k; transactionsLeft++)
                {
                    int profit = -1e9;
                    if (canBuy)
                    {
                        int buy = -arr[currDay] + front[0][transactionsLeft];
                        int notBuy = front[1][transactionsLeft];
                        profit = max(buy, notBuy);
                    }
                    else
                    {
                        int sell = arr[currDay] + front[1][transactionsLeft - 1];
                        int notSell = front[0][transactionsLeft];
                        profit = max(sell, notSell);
                    }
                    curr[canBuy][transactionsLeft] = profit;
                }
            }
            front = curr;
        }

        return front[1][k];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * 2 * K)
> Space Complexity: O(N * 2 * K)
*/

class Solution
{
public:
    int stockBuySell(vector<int> arr, int n, int k)
    {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int currDay = n - 1; currDay >= 0; currDay--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                for (int transactionsLeft = 1; transactionsLeft <= k; transactionsLeft++)
                {
                    int profit = -1e9;
                    if (canBuy)
                    {
                        int buy = -arr[currDay] + dp[currDay + 1][0][transactionsLeft];
                        int notBuy = dp[currDay + 1][1][transactionsLeft];
                        profit = max(buy, notBuy);
                    }
                    else
                    {
                        int sell = arr[currDay] + dp[currDay + 1][1][transactionsLeft - 1];
                        int notSell = dp[currDay + 1][0][transactionsLeft];
                        profit = max(sell, notSell);
                    }
                    dp[currDay][canBuy][transactionsLeft] = profit;
                }
            }
        }

        return dp[0][1][k];
    }
};

//! Memoization DP
/*
> Time Complexity: O(N * 2 * K)
> Space Complexity: O(N * 2 * K) + O(N)
*/

class Solution
{
public:
    int helper(vector<int> &arr, int currDay, int canBuy, int transactionsLeft, vector<vector<vector<int>>> &dp)
    {
        if (currDay == arr.size() || transactionsLeft == 0)
        {
            return 0;
        }

        if (dp[currDay][canBuy][transactionsLeft] != -1)
        {
            return dp[currDay][canBuy][transactionsLeft];
        }

        int profit = -1e9;
        if (canBuy)
        {
            int buy = -arr[currDay] + helper(arr, currDay + 1, 0, transactionsLeft, dp);
            int notBuy = helper(arr, currDay + 1, 1, transactionsLeft, dp);
            profit = max(buy, notBuy);
        }
        else
        {
            int sell = arr[currDay] + helper(arr, currDay + 1, 1, transactionsLeft - 1, dp);
            int notSell = helper(arr, currDay + 1, 0, transactionsLeft, dp);
            profit = max(sell, notSell);
        }
        return dp[currDay][canBuy][transactionsLeft] = profit;
    }

    int stockBuySell(vector<int> arr, int n, int k)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return helper(arr, 0, 1, k, dp);
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
    int helper(vector<int> &arr, int currDay, int canBuy, int transactionsLeft)
    {
        if (currDay == arr.size() || transactionsLeft == 0)
        {
            return 0;
        }

        int profit = -1e9;
        if (canBuy)
        {
            int buy = -arr[currDay] + helper(arr, currDay + 1, 0, transactionsLeft);
            int notBuy = helper(arr, currDay + 1, 1, transactionsLeft);
            profit = max(buy, notBuy);
        }
        else
        {
            int sell = arr[currDay] + helper(arr, currDay + 1, 1, transactionsLeft - 1);
            int notSell = helper(arr, currDay + 1, 0, transactionsLeft);
            profit = max(sell, notSell);
        }
        return profit;
    }

    int stockBuySell(vector<int> arr, int n, int k)
    {
        return helper(arr, 0, 1, k);
    }
};
