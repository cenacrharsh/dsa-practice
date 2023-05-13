#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=y0U4GEMEMvI

//! Space Optimized Tabulation DP

//! Tabulation DP -> Bottom Up Approach
#define mod 1000000007;
class Solution
{
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        int ans = 0;
        for (int len = 1; len <= high; len++)
        {
            if (len >= zero)
            {
                dp[len] = dp[len - zero];
            }

            if (len >= one)
            {
                dp[len] = (dp[len] + dp[len - one]) % mod;
            }

            if (len >= low)
            {
                ans = (ans + dp[len]) % mod;
            }
        }
        return ans;
    }
};

//! Memoization DP

/*
> Time Complexity: O(high)
> Space Complexity: O(high)
*/

#define mod 1000000007;
class Solution
{
public:
    int numGoodStrings(int len, int zero, int one, vector<int> &dp)
    {
        if (len < 0)
        {
            return 0;
        }
        if (len == 0)
        {
            return 1;
        }

        if (dp[len] != -1)
        {
            return dp[len];
        }

        long long sum = (numGoodStrings(len - zero, zero, one, dp) + numGoodStrings(len - one, zero, one, dp)) % mod;

        return dp[len] = sum;
    }
    int countGoodStrings(int low, int high, int zero, int one)
    {
        int ans = 0;
        vector<int> dp(high + 1, -1);
        for (int len = low; len <= high; len++)
        {
            ans = (ans + numGoodStrings(len, zero, one, dp)) % mod;
        }
        return ans;
    }
};

//! Recursion -> Top Down Approach
#define mod 1000000007
class Solution
{
public:
    int numGoodStrings(int len, int zero, int one)
    {
        if (len < 0)
        {
            return 0;
        }
        if (len == 0)
        {
            return 1;
        }

        long long sum = (numGoodStrings(len - zero, zero, one) +
                        numGoodStrings(len - one, zero, one)) % mod;

        return sum;
    }
    int countGoodStrings(int low, int high, int zero, int one)
    {
        int ans = 0;
        for (int len = low; len <= high; len++)
        {
            ans = (ans + numGoodStrings(len, zero, one)) % mod;
        }
        return ans;
    }
};