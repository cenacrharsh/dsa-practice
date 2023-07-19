#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=NPZn9jBrX8U&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=13

//- f(index1, index2) -> LCS of str1 till index1 & str2 till index2

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(N * M)
> Space Complexity: O(M)
*/

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<int> prev(n2 + 1, 0), curr(n2 + 1, 0);

        for (int j = 0; j <= n2; j++)
        {
            prev[j] = 0;
        }

        for (int index1 = 1; index1 <= n1; index1++)
        {
            for (int index2 = 1; index2 <= n2; index2++)
            {
                if (text1[index1 - 1] == text2[index2 - 1])
                {
                    curr[index2] = 1 + prev[index2 - 1];
                }
                else
                {
                    curr[index2] = max(prev[index2], curr[index2 - 1]);
                }
            }
            prev = curr;
        }

        return prev[n2];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * M)
> Space Complexity: O(N * M)
*/

//@ shifting one index to the right, from f(n - 1, m - 1) to f(n, m)
//@ now f(i, j) => f(text1[0...i-1], text2[0...j-1])
//@ also f(0,j) | f(i, 0) = 0 now, since 0 indicates -1 now

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= n2; j++)
        {
            dp[0][j] = 0;
        }

        for (int index1 = 1; index1 <= n1; index1++)
        {
            for (int index2 = 1; index2 <= n2; index2++)
            {
                if (text1[index1 - 1] == text2[index2 - 1])
                {
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                }
                else
                {
                    dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
                }
            }
        }

        return dp[n1][n2];
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * M)
> Space Complexity: O(N * M) + O(N + M)
*/

//* with index shift

class Solution
{
public:
    int helper(int index1, int index2, string text1, string text2, vector<vector<int>> &dp)
    {
        if (index1 == 0 || index2 == 0)
        {
            return 0;
        }

        if (dp[index1][index2] != -1)
        {
            return dp[index1][index2];
        }

        if (text1[index1 - 1] == text2[index2 - 1])
        {
            return 1 + helper(index1 - 1, index2 - 1, text1, text2, dp);
        }

        return dp[index1][index2] = max(
                   helper(index1 - 1, index2, text1, text2, dp),
                   helper(index1, index2 - 1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return helper(n1, n2, text1, text2, dp);
    }
};

//* without index shift

class Solution
{
public:
    int helper(int index1, int index2, string text1, string text2, vector<vector<int>> &dp)
    {
        if (index1 < 0 || index2 < 0)
        {
            return 0;
        }

        if (dp[index1][index2] != -1)
        {
            return dp[index1][index2];
        }

        if (text1[index1] == text2[index2])
        {
            return 1 + helper(index1 - 1, index2 - 1, text1, text2, dp);
        }

        return dp[index1][index2] = max(
                   helper(index1 - 1, index2, text1, text2, dp),
                   helper(index1, index2 - 1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return helper(n1 - 1, n2 - 1, text1, text2, dp);
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(2^N * 2^M )
> Space Complexity: O(N + M)
*/

class Solution
{
public:
    int helper(int index1, int index2, string text1, string text2)
    {
        if (index1 < 0 || index2 < 0)
        {
            return 0;
        }

        if (text1[index1] == text2[index2])
        {
            return 1 + helper(index1 - 1, index2 - 1, text1, text2);
        }

        return max(helper(index1 - 1, index2, text1, text2),
                   helper(index1, index2 - 1, text1, text2));
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        return helper(n1 - 1, n2 - 1, text1, text2);
    }
};