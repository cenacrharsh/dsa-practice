#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=fJaKO8FbDdo&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=18

//- f(n - 1, m - 1) => find minimum number of operations required to convert s1[0...n-1] to s2[0...m-1]

//! Space Optimized Tabulation DP

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // base case 1, every col of first row has value = col number
        for (int j = 0; j <= m; j++)
        {
            prev[j] = j;
        }

        for (int i = 1; i <= n; i++)
        {
            // base case 2, first col of every row has value = row number
            curr[0] = i;

            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    curr[j] = prev[j - 1];
                }
                else
                {
                    //* insert
                    int insertOp = curr[j - 1];

                    //* delete
                    int deleteOp = prev[j];

                    //* replace
                    int replaceOp = prev[j - 1];

                    curr[j] = 1 + min(insertOp, min(deleteOp, replaceOp));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

//! Tabulation DP -> Bottom Up Approach

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // base case
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    //* insert
                    int insertOp = dp[i][j - 1];

                    //* delete
                    int deleteOp = dp[i - 1][j];

                    //* replace
                    int replaceOp = dp[i - 1][j - 1];

                    dp[i][j] = 1 + min(insertOp, min(deleteOp, replaceOp));
                }
            }
        }
        return dp[n][m];
    }
};

//! Memoization DP
class Solution
{
public:
    int helper(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
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
            return dp[i][j] = helper(i - 1, j - 1, word1, word2, dp);
        }
        else
        {
            //* insert
            int insertOp = helper(i, j - 1, word1, word2, dp);

            //* delete
            int deleteOp = helper(i - 1, j, word1, word2, dp);

            //* replace
            int replaceOp = helper(i - 1, j - 1, word1, word2, dp);

            return dp[i][j] = 1 + min(insertOp, min(deleteOp, replaceOp));
        }
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(n, m, word1, word2, dp);
    }
};

//! Recursion -> Top Down Approach

//@ with index shifting
class Solution
{
public:
    int helper(int i, int j, string &word1, string &word2)
    {
        if (i == 0)
        {
            return j;
        }
        if (j == 0)
        {
            return i;
        }

        if (word1[i - 1] == word2[j - 1])
        {
            return helper(i - 1, j - 1, word1, word2);
        }
        else
        {
            //* insert
            int insertOp = helper(i, j - 1, word1, word2);

            //* delete
            int deleteOp = helper(i - 1, j, word1, word2);

            //* replace
            int replaceOp = helper(i - 1, j - 1, word1, word2);

            return 1 + min(insertOp, min(deleteOp, replaceOp));
        }
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        return helper(n, m, word1, word2);
    }
};

//@ without index shifting
class Solution
{
public:
    int helper(int i, int j, string &word1, string &word2)
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
            return helper(i - 1, j - 1, word1, word2);
        }
        else
        {
            //* insert
            int insertOp = helper(i, j - 1, word1, word2);

            //* delete
            int deleteOp = helper(i - 1, j, word1, word2);

            //* replace
            int replaceOp = helper(i - 1, j - 1, word1, word2);

            return 1 + min(insertOp, min(deleteOp, replaceOp));
        }
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        return helper(n - 1, m - 1, word1, word2);
    }
};
