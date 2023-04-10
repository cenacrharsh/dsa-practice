#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Space Optimized Tabulation DP
class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;

        int prev = 1;
        int prev2 = 1;
        int prev3 = 0;

        for (int i = 3; i <= n; i++)
        {
            int curr = prev + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

//! Tabulation DP -> Bottom Up Approach
class Solution
{
public:
    int tribonacci(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        if (n > 0)
            dp[1] = 1;
        if (n > 1)
            dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};

//! Memoization DP
class Solution
{
public:
    int helper(int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp) + helper(n - 3, dp);
    }
    int tribonacci(int n)
    {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};

//! Recursion -> Top Down Approach
class Solution
{
public:
    int helper(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;

        return helper(n - 1) + helper(n - 2) + helper(n - 3);
    }
    int tribonacci(int n)
    {
        return helper(n);
    }
};
