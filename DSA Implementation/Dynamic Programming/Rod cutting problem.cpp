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
> Time Complexity: O(N * N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int rodCutting(vector<int> price, int n)
    {
        //* Treat this problem as we have rods of varying lenghts each having a price, sum them up to reach value n with maxmizing the price - just like unbounded knapsack
        //* f(N - 1, N): till index N what is the max value we can obtain

        vector<int> curr(n + 1, 0);

        for (int lengthLeft = 0; lengthLeft <= n; lengthLeft++)
        {
            curr[lengthLeft] = lengthLeft * price[0];
        }

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int lengthLeft = 0; lengthLeft <= n; lengthLeft++)
            {
                int notTake = 0 + curr[lengthLeft];
                int take = 0;
                int rodLength = currIndex + 1;
                if (rodLength <= lengthLeft)
                {
                    take = price[currIndex] + curr[lengthLeft - rodLength];
                }

                curr[lengthLeft] = max(notTake, take);
            }
        }

        return curr[n];
    }
};

//-------------------------------------------------------------------------------------------------------------------

/*
> Time Complexity: O(N * N)
> Space Complexity: O(2N)
*/

class Solution
{
public:
    int rodCutting(vector<int> price, int n)
    {
        //* Treat this problem as we have rods of varying lenghts each having a price, sum them up to reach value n with maxmizing the price - just like unbounded knapsack
        //* f(N - 1, N): till index N what is the max value we can obtain

        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for (int lengthLeft = 0; lengthLeft <= n; lengthLeft++)
        {
            prev[lengthLeft] = lengthLeft * price[0];
        }

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int lengthLeft = 0; lengthLeft <= n; lengthLeft++)
            {
                int notTake = 0 + prev[lengthLeft];
                int take = 0;
                int rodLength = currIndex + 1;
                if (rodLength <= lengthLeft)
                {
                    take = price[currIndex] + curr[lengthLeft - rodLength];
                }

                curr[lengthLeft] = max(notTake, take);
            }
            prev = curr;
        }

        return prev[n];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * N)
> Space Complexity: O(N * N)
*/

class Solution
{
public:
    int rodCutting(vector<int> price, int n)
    {
        //* Treat this problem as we have rods of varying lenghts each having a price, sum them up to reach value n with maxmizing the price - just like unbounded knapsack
        //* f(N - 1, N): till index N what is the max value we can obtain

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int lengthLeft = 0; lengthLeft <= n; lengthLeft++)
        {
            dp[0][lengthLeft] = lengthLeft * price[0];
        }

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int lengthLeft = 0; lengthLeft <= n; lengthLeft++)
            {
                int notTake = 0 + dp[currIndex - 1][lengthLeft];
                int take = 0;
                int rodLength = currIndex + 1;
                if (rodLength <= lengthLeft)
                {
                    take = price[currIndex] + dp[currIndex][lengthLeft - rodLength];
                }

                dp[currIndex][lengthLeft] = max(notTake, take);
            }
        }

        return dp[n - 1][n];
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * N)
> Space Complexity: O(N * N) + O(N)
*/

class Solution
{
public:
    int helper(vector<int> price, int currIndex, int lengthLeft, vector<vector<int>> &dp)
    {
        //* we'll take 1 inch rods * lengthLeft because that is the len of rod we require
        if (currIndex == 0)
        {
            return lengthLeft * price[0];
        }

        if (dp[currIndex][lengthLeft] != -1)
        {
            return dp[currIndex][lengthLeft];
        }

        int notTake = 0 + helper(price, currIndex - 1, lengthLeft, dp);
        int take = 0;
        int rodLength = currIndex + 1;
        if (rodLength <= lengthLeft)
        {
            take = price[currIndex] + helper(price, currIndex, lengthLeft - rodLength, dp);
        }

        return dp[currIndex][lengthLeft] = max(notTake, take);
    }

    int rodCutting(vector<int> price, int n)
    {
        //* Treat this problem as we have rods of varying lenghts each having a price, sum them up to reach value n with maxmizing the price - just like unbounded knapsack
        //* f(N - 1, N): till index N what is the max value we can obtain

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(price, n - 1, n, dp);
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
    int helper(vector<int> price, int currIndex, int lengthLeft)
    {
        //* we'll take 1 inch rods * lengthLeft because that is the len of rod we require
        if (currIndex == 0)
        {
            return lengthLeft * price[0];
        }

        int notTake = 0 + helper(price, currIndex - 1, lengthLeft);
        int take = 0;
        int rodLength = currIndex + 1;
        if (rodLength <= lengthLeft)
        {
            take = price[currIndex] + helper(price, currIndex, lengthLeft - rodLength);
        }

        return max(notTake, take);
    }

    int rodCutting(vector<int> price, int n)
    {
        //* Treat this problem as we have rods of varying lenghts each having a price, sum them up to reach value n with maxmizing the price - just like unbounded knapsack
        //* f(N - 1, N): till index N what is the max value we can obtain
        return helper(price, n - 1, n);
    }
};
