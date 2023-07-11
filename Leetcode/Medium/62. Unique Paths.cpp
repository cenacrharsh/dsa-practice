#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=t_f0nwwdg5o

//! Combination

/*
> Time Complexity: O(n-1) || O(m-1)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // num of directions we have to choose from
        int N = m + n - 2; // m - 1 in right direction + n - 1 in down direction
        int R = m - 1;     // or n - 1; as m + n - 2 C m - 1 = m + n - 2 C n - 1

        // to calculate nCr = n * n - 1 * n - 2.. r times/1 * 2 * .. r times
        double res = 1;
        for (int i = 1; i <= R; i++)
        {
            res = res * (N - R + i) / i; // for 10C3 i gives 1 * 2 * 3, N - R + i (as N - R = 7, then 7 + i) gives 8 * 9 * 10
        }

        return (int)res;
    }
};

/*------------------------------------------------------------------*/

// # Tutorial: https://www.youtube.com/watch?v=sdE0A2Oxofw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=25

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(n * m)
> Space Complexity: O(n)
*/

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    curr[j] = 1;
                }
                else
                {
                    int up = 0;
                    int left = 0;
                    if (i - 1 >= 0)
                    {
                        up = prev[j];
                    }
                    if (j - 1 >= 0)
                    {
                        left = curr[j - 1];
                    }
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(n * m)
> Space Complexity: O(n + m)
*/

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[0][0] = 1;
                }
                else
                {
                    int up = 0;
                    int left = 0;
                    if (i - 1 >= 0)
                    {
                        up = dp[i - 1][j];
                    }
                    if (j - 1 >= 0)
                    {
                        left = dp[i][j - 1];
                    }
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

//! Memoization DP

/*
> Time Complexity: O(n * m)
> Space Complexity: O((m-1) + (n-1)) + O(m * n) => recursive stack space + DP vector
*/

class Solution
{
public:
    int helper(int row, int col, vector<vector<int>> &dp)
    {
        if (row == 0 && col == 0)
        {
            return 1;
        }
        if (row < 0 || col < 0)
        {
            return 0;
        }

        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }

        int up = helper(row - 1, col, dp);
        int left = helper(row, col - 1, dp);

        return dp[row][col] = up + left;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, dp);
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(2^(m*n))
> Space Complexity: O((m-1) + (n-1)) => path length
*/
class Solution
{
public:
    int helper(int row, int col)
    {
        if (row == 0 && col == 0)
        {
            return 1;
        }
        if (row < 0 || col < 0)
        {
            return 0;
        }

        int up = helper(row - 1, col);
        int left = helper(row, col - 1);

        return up + left;
    }

    int uniquePaths(int m, int n)
    {
        return helper(m - 1, n - 1);
    }
};
