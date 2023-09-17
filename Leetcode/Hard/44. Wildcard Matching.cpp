#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=ZmlQ3vgAOMo&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=17

//- f(n - 1, m - 1) => is the str1[0...n-1] matching with str2[0...m-1]

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(N * M)
> Space Complexity: O(2M)
*/

class Solution
{
public:
    bool isMatch(string text, string pattern)
    {
        int n = pattern.size();
        int m = text.size();

        //* 0th row is prev -> dp[0], 1st row is curr
        vector<bool> prev(m + 1, false), curr(m + 1, false);

        prev[0] = true;
        for (int j = 1; j <= m; j++)
        {
            prev[j] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            //* curr is the current row, hence it's 0th col has to be assigned every time
            bool flag = true;
            for (int k = 1; k <= i; k++)
            {
                if (pattern[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            //* for every row, we are assigning the 0th col's value
            curr[0] = flag;

            for (int j = 1; j <= m; j++)
            {
                if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
                {
                    curr[j] = prev[j - 1];
                }
                else if (pattern[i - 1] == '*')
                {
                    curr[j] = prev[j] || curr[j - 1];
                }
                else
                {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * M)
> Space Complexity: O(N * M)
*/

class Solution
{
public:
    bool isMatch(string text, string pattern)
    {
        int n = pattern.size();
        int m = text.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        //* base case
        //@ both pattern and text exhausted
        dp[0][0] = true;
        //@ pattern exhausted, text left
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = false;
        }
        //@ pattern left, text exhausted
        for (int i = 1; i <= n; i++)
        {
            bool flag = true;
            for (int k = 1; k <= i; k++)
            {
                if (pattern[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pattern[i - 1] == '*')
                {
                    //* we consider 2 cases, we assume * matches nothing, and we assume it matches 1 character, due to recursion we'll one by one check all possibilites of assuming string to match 0,1,2,3... charcters until possible
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else
                {
                    //* if characters don't match and s[i] != ? or * we return false
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * M)
> Space Complexity: O(N * M) + O(N + M) -> Recursive stack space
*/

//@ with index shifting
class Solution
{
public:
    bool helper(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        //* str1 & str2 get exhausted
        if (i == 0 && j == 0)
            return true;

        //* str1 get exhausted but str2 is still left
        if (i == 0 && j > 0)
            return false;

        //* str1 is left but str2 is exhausted
        if (j == 0 && i > 0)
        {
            for (int k = 1; k <= i; k++)
            {
                if (s[k - 1] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i - 1] == p[j - 1] || s[i - 1] == '?')
        {
            return dp[i][j] = helper(i - 1, j - 1, s, p, dp);
        }
        if (s[i - 1] == '*')
        {
            //* we consider 2 cases, we assume * matches nothing, and we assume it matches 1 character, due to recursion we'll one by one check all possibilites of assuming string to match 0,1,2,3... charcters until possible
            return dp[i][j] = helper(i - 1, j, s, p, dp) || helper(i, j - 1, s, p, dp);
        }

        //* if characters don't match and s[i] != ? or * we return false
        return dp[i][j] = false;
    }

    bool isMatch(string text, string pattern)
    {
        int n = pattern.size();
        int m = text.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(n, m, pattern, text, dp);
    }
};

//@ without index shifting
class Solution
{
public:
    bool helper(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        //* str1 & str2 get exhausted
        if (i < 0 && j < 0)
            return true;

        //* str1 get exhausted but str2 is still left
        if (i < 0 && j >= 0)
            return false;

        //* str1 is left but str2 is exhausted
        if (j < 0 && i >= 0)
        {
            for (int k = 0; k <= i; k++)
            {
                if (s[k] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == p[j] || s[i] == '?')
        {
            return dp[i][j] = helper(i - 1, j - 1, s, p, dp);
        }
        if (s[i] == '*')
        {
            //* we consider 2 cases, we assume * matches nothing, and we assume it matches 1 character, due to recursion we'll one by one check all possibilites of assuming string to match 0,1,2,3... charcters until possible
            return dp[i][j] = helper(i - 1, j, s, p, dp) || helper(i, j - 1, s, p, dp);
        }

        //* if characters don't match and s[i] != ? or * we return false
        return dp[i][j] = false;
    }

    bool isMatch(string text, string pattern)
    {
        int n = pattern.size();
        int m = text.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, pattern, text, dp);
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(2^N * 2^M)
> Space Complexity: O(N + M) -> Recursive stack space
*/

class Solution
{
public:
    bool helper(int i, int j, string &s, string &p)
    {
        //* str1 & str2 get exhausted
        if (i < 0 && j < 0)
            return true;

        //* str1 get exhausted but str2 is still left
        if (i < 0 && j >= 0)
            return false;

        //* str1 is left but str2 is exhausted
        if (j < 0 && i >= 0)
        {
            for (int k = 0; k <= i; k++)
            {
                if (s[k] != '*')
                    return false;
            }
            return true;
        }

        if (s[i] == p[j] || s[i] == '?')
        {
            return helper(i - 1, j - 1, s, p);
        }
        if (s[i] == '*')
        {
            //* we consider 2 cases, we assume * matches nothing, and we assume it matches 1 character, due to recursion we'll one by one check all possibilites of assuming string to match 0,1,2,3... charcters until possible
            return helper(i - 1, j, s, p) || helper(i, j - 1, s, p);
        }

        //* if characters don't match and s[i] != ? or * we return false
        return false;
    }

    bool isMatch(string text, string pattern)
    {
        int n = pattern.size();
        int m = text.size();
        return helper(n - 1, m - 1, pattern, text);
    }
};