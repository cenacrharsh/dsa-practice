#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=fJaKO8FbDdo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=35

//! Brute Force Recursion

/*
> Time Complexity: O(exponential)
> Space Complexity: O(n+m) => auxiliary stack space
*/

class Solution
{
public:
    int f(int i, int j, string &word1, string &word2)
    {
        if (i < 0)
        {
            return j + 1;
        }
        if (j < 0)
        {
            return i + 1;
        }

        if (word1[i] == word2[j])
        {
            return f(i - 1, j - 1, word1, word2);
        }

        // f(i, j-1) => insert
        // f(i-1, j) => delete
        // f(i-1, j-1) => replace
        return 1 + min(f(i, j - 1, word1, word2), min(f(i - 1, j, word1, word2), f(i - 1, j - 1, word1, word2)));
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        return f(n - 1, m - 1, word1, word2);
    }
};

//! Memoization DP

/*
> Time Complexity: O(n*m)
> Space Complexity: O(n*m) + O(n+m)
*/

class Solution
{
public:
    int f(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        if (i < 0)
        {
            return j + 1;
        }
        if (j < 0)
        {
            return i + 1;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (word1[i] == word2[j])
        {
            return dp[i][j] = f(i - 1, j - 1, word1, word2, dp);
        }

        // f(i, j-1) => insert
        // f(i-1, j) => delete
        // f(i-1, j-1) => replace
        return dp[i][j] = 1 + min(f(i, j - 1, word1, word2, dp),
                                  min(f(i - 1, j, word1, word2, dp),
                                      f(i - 1, j - 1, word1, word2, dp)));
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, word1, word2, dp);
    }
};

//! Tabulation DP || Bottom Up

/*
> Time Complexity: O(n*m)
> Space Complexity: O(n*m)
*/

//* first shift indexes
class Solution
{
public:
    int f(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            return j;
        }
        if (j == 0)
        {
            return i;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (word1[i - 1] == word2[j - 1])
        {
            return dp[i][j] = f(i - 1, j - 1, word1, word2, dp);
        }

        // f(i, j-1) => insert
        // f(i-1, j) => delete
        // f(i-1, j-1) => replace
        return dp[i][j] = 1 + min(f(i, j - 1, word1, word2, dp),
                                  min(f(i - 1, j, word1, word2, dp),
                                      f(i - 1, j - 1, word1, word2, dp)));
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, word1, word2, dp);
    }
};

//* now apply tabulation
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base Cases
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }

        // Invert i and j
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // same recurrence relation as Top Down
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // f(i, j-1) => insert
                    // f(i-1, j) => delete
                    // f(i-1, j-1) => replace
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }

        return dp[n][m];
    }
};

//* further space optimization using 1D array
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // Base Cases
        for (int j = 0; j <= m; j++)
        {
            prev[j] = j;
        }

        // Invert i and j
        for (int i = 1; i <= n; i++)
        {
            curr[0] = i; // aq to 2nd base case, each rows first element is always == i
            for (int j = 1; j <= m; j++)
            {
                // same recurrence relation as Top Down
                if (word1[i - 1] == word2[j - 1])
                {
                    curr[j] = prev[j - 1];
                }
                else
                {
                    // f(i, j-1) => insert
                    // f(i-1, j) => delete
                    // f(i-1, j-1) => replace
                    curr[j] = 1 + min(curr[j - 1], min(prev[j], prev[j - 1]));
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};