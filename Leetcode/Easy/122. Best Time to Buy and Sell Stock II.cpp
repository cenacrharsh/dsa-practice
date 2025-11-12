#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
> Space Complexity: O(2)
*/

class Solution
{
public:
    int stockBuySell(vector<int> arr, int n)
    {
        //* f(currDay, canBuyOrNot): Max profit one can obtain by buying at i and selling at j

        vector<int> front(2, 0);
        front[0] = 0;
        front[1] = 0;

        for (int currDay = n - 1; currDay >= 0; currDay--)
        {
            vector<int> curr(2, 0);
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                long profit = 0;
                if (canBuy)
                {
                    int buy = -arr[currDay] + front[0];
                    int notBuy = front[1];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = arr[currDay] + front[1];
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

//! Tabulation DP -> Top Down Approach

/*
> Time Complexity: O(N * 2)
> Space Complexity: O(N * 2)
*/

class Solution
{
public:
    int stockBuySell(vector<int> arr, int n)
    {
        //* f(currDay, canBuyOrNot): Max profit one can obtain by buying at i and selling at j

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = 0;
        dp[n][1] = 0;

        for (int currDay = n - 1; currDay >= 0; currDay--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                long profit = 0;
                if (canBuy)
                {
                    int buy = -arr[currDay] + dp[currDay + 1][0];
                    int notBuy = dp[currDay + 1][1];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = arr[currDay] + dp[currDay + 1][1];
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
> Space Complexity: O(N * 2) + O(N + 2)
*/

class Solution
{
public:
    int helper(vector<int> &arr, int currDay, int canBuy, vector<vector<int>> &dp)
    {
        if (currDay == arr.size())
        {
            return 0; //* if array is over even if are holding a stock no profit can be made so 0
        }

        if (dp[currDay][canBuy] != -1)
        {
            return dp[currDay][canBuy];
        }

        if (canBuy)
        {
            int buy = -arr[currDay] + helper(arr, currDay + 1, 0, dp);
            int notBuy = helper(arr, currDay + 1, 1, dp);
            return dp[currDay][canBuy] = max(buy, notBuy);
        }
        else
        {
            int sell = arr[currDay] + helper(arr, currDay + 1, 1, dp);
            int notSell = helper(arr, currDay + 1, 0, dp);
            return dp[currDay][canBuy] = max(sell, notSell);
        }
    }

    int stockBuySell(vector<int> arr, int n)
    {
        //* f(currDay, canBuyOrNot): Max profit one can obtain by buying at i and selling at j

        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(arr, 0, 1, dp);
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
    int helper(vector<int> &arr, int currDay, int canBuy)
    {
        if (currDay == arr.size())
        {
            return 0; //* if array is over even if are holding a stock no profit can be made so 0
        }

        int profit = INT_MIN;
        if (canBuy)
        {
            int buy = -arr[currDay] + helper(arr, currDay + 1, 0);
            int notBuy = helper(arr, currDay + 1, 1);
            profit = max(profit, max(buy, notBuy));
        }
        else
        {
            int sell = arr[currDay] + helper(arr, currDay + 1, 1);
            int notSell = helper(arr, currDay + 1, 0);
            profit = max(profit, max(sell, notSell));
        }
        return profit;
    }

    int stockBuySell(vector<int> arr, int n)
    {
        //* f(currDay, canBuyOrNot): Max profit one can obtain by buying at i and selling at j

        return helper(arr, 0, 1);
    }
};
