#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=tyB0ztf0DNY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=3

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        int secondPrev = 0;
        int prev = 1;
        for (int i = 2; i <= n; i++)
        {
            int curr = prev + secondPrev;
            secondPrev = prev;
            prev = curr;
        }
        //* as when loop finishes, the last calculated value of curr in stored in prev
        return prev;
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

class Solution
{
public:
    int fib(int n)
    {
        // we need base case as if n == 0, we can't access dp[1]
        if (n == 0 || n == 1)
        {
            return n;
        }
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            //* intuition for space optimization, all we need to calculate dp[i] is the value of previous dp and second previous dp, not the entire array
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

//! Memoization DP

/*
> Time Complexity: O(n)
> Space Complexity: O(n) + O(n) => dp vector + stack space
*/

class Solution
{
public:
    int helper(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }
        else
        {
            return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
        }

        return dp[n];
    }
    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(2^n) => exponential
> Space Complexity: O(2^n) => auxiliary stack space
*/

class Solution
{
public:
    int helper(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }

        return helper(n - 1) + helper(n - 2);
    }
    int fib(int n)
    {
        return helper(n);
    }
};
