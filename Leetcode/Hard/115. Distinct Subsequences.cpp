#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=nVG7eTiD2bY&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=15

//- f(n-1, m-1) -> no of distinct subseq. of str2[0...m-1] in str1[0...n-1]

//! Space Optimized Tabulation DP

//@ 1 array

/*
> Time Complexity: O(N * M)
> Space Complexity: O(M)
*/

int mod = 1e9 + 7;
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        vector<int> prev(t.size() + 1, 0);

        prev[0] = 1;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = t.size(); j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])
                {
                    prev[j] = (prev[j - 1] + prev[j]) % mod;
                }
                // else
                // {
                //     prev[j] = prev[j];
                // }
            }
        }

        return prev[t.size()];
    }
};

//@ 2 arrays

/*
> Time Complexity: O(N * M)
> Space Complexity: O(2M)
*/

int mod = 1e9 + 7;
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        vector<int> prev(t.size() + 1, 0), curr(t.size() + 1, 0);

        prev[0] = curr[0] = 1;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    curr[j] = (prev[j - 1] + prev[j]) % mod;
                }
                else
                {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return prev[t.size()];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * M)
> Space Complexity: O(N + M)
*/

int mod = 1e9 + 7;
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        //* exhaust string t
        for (int i = 0; i <= s.size(); i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[s.size()][t.size()];
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * M)
> Space Complexity: O(N * M) + O(N + M)
*/

class Solution
{
public:
    int helper(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        //* when we exhaust string t, means we matched all characters
        if (j < 0)
        {
            return 1;
        }

        //* when we exhaust string s, means we finished string s without matching all char of string t
        if (i < 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == t[j])
        {
            //* we explore both cases, when we choose the s[i] as the matching character and when we don't
            return dp[i][j] = helper(i - 1, j - 1, s, t, dp) + helper(i - 1, j, s, t, dp);
        }
        else
        {
            return dp[i][j] = helper(i - 1, j, s, t, dp);
        }
    }

    int numDistinct(string s, string t)
    {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return helper(s.size() - 1, t.size() - 1, s, t, dp);
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(2^N * 2^M)
> Space Complexity: O(N + M)
*/

class Solution
{
public:
    int helper(int i, int j, string s, string t)
    {
        //* when we exhaust string t, means we matched all characters
        if (j < 0)
        {
            return 1;
        }

        //* when we exhaust string s, means we finished string s without matching all char of string t
        if (i < 0)
        {
            return 0;
        }

        if (s[i] == t[j])
        {
            //* we explore both cases, when we choose the s[i] as the matching character and when we don't
            return helper(i - 1, j - 1, s, t) + helper(i - 1, j, s, t);
        }
        else
        {
            return helper(i - 1, j, s, t);
        }
    }

    int numDistinct(string s, string t)
    {
        return helper(s.size() - 1, t.size() - 1, s, t);
    }
};