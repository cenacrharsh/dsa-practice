#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
    int stockBuySell(vector<int> arr, int n)
    {
        vector<vector<int>> front(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        //* dp array is already initialized to 0 so no need to handle base cases

        for (int currDay = n - 1; currDay >= 0; currDay--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                //* transactionsLeft = 0 is part of base case where every vaule = 0 so we skip calculation for it
                for (int transactionsLeft = 1; transactionsLeft <= 2; transactionsLeft++)
                {
                    int profit = 0;
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
        return front[1][2];
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
    int stockBuySell(vector<int> arr, int n)
    {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        //* dp array is already initialized to 0 so no need to handle base cases

        for (int currDay = n - 1; currDay >= 0; currDay--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                //* transactionsLeft = 0 is part of base case where every vaule = 0 so we skip calculation for it
                for (int transactionsLeft = 1; transactionsLeft <= 2; transactionsLeft++)
                {
                    int profit = 0;
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

        return dp[0][1][2];
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
    int helper(vector<int> arr, int currDay, int canBuy, int transactionsLeft, vector<vector<vector<int>>> &dp)
    {
        if (transactionsLeft == 0)
        {
            return 0;
        }
        else if (currDay == arr.size())
        {
            return 0;
        }

        if (dp[currDay][canBuy][transactionsLeft] != -1)
        {
            return dp[currDay][canBuy][transactionsLeft];
        }

        int profit = 0;
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

    int stockBuySell(vector<int> arr, int n)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(arr, 0, 1, 2, dp);
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
    int helper(vector<int> arr, int currDay, int canBuy, int transactionsLeft)
    {
        if (transactionsLeft == 0)
        {
            return 0;
        }
        else if (currDay == arr.size())
        {
            return 0;
        }

        int profit = 0;
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

    int stockBuySell(vector<int> arr, int n)
    {
        return helper(arr, 0, 1, 2);
    }
};
