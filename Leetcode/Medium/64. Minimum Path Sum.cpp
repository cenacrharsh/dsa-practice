#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=_rgTlyky1uQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=11

//! Space Optimized Tabulation DP
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    curr[j] = grid[i][j];
                else
                {
                    int up = grid[i][j];
                    if (i > 0)
                    {
                        up += prev[j];
                    }
                    else
                    {
                        // we want to ignore the path if it's out of bounds
                        up += 1e9;
                    }

                    int left = grid[i][j];
                    if (j > 0)
                    {
                        left += curr[j - 1];
                    }
                    else
                    {
                        // we want to ignore the path if it's out of bounds
                        left += 1e9;
                    }

                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};

//! Tabulation DP -> Bottom Up Approach
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else
                {
                    int up = grid[i][j];
                    if (i > 0)
                    {
                        up += dp[i - 1][j];
                    }
                    else
                    {
                        // we want to ignore the path if it's out of bounds
                        up += 1e9;
                    }

                    int left = grid[i][j];
                    if (j > 0)
                    {
                        left += dp[i][j - 1];
                    }
                    else
                    {
                        // we want to ignore the path if it's out of bounds
                        left += 1e9;
                    }

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

//! Memoization DP
class Solution
{
public:
    int helper(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (row == 0 && col == 0)
        {
            return grid[0][0]; //* we know it will be part of our path
        }

        if (row < 0 || col < 0)
        {
            return 1e9;
        }

        if (dp[row][col] != -1)
            return dp[row][col];

        int up = grid[row][col] + helper(row - 1, col, grid, dp);
        int left = grid[row][col] + helper(row, col - 1, grid, dp);

        return dp[row][col] = min(up, left);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, grid, dp);
    }
};

//! Recursion -> Top Down Approach
class Solution
{
public:
    int helper(int row, int col, vector<vector<int>> &grid)
    {
        if (row == 0 && col == 0)
        {
            return grid[0][0]; //* we know it will be part of our path
        }

        if (row < 0 || col < 0)
        {
            return 1e9; //* we want to exclude this path, we can't use INT_MAX as it's the biggest number int can hold and so we can't add anything to it later
        }

        int up = grid[row][col] + helper(row - 1, col, grid);
        int left = grid[row][col] + helper(row, col - 1, grid);

        return min(up, left);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        return helper(m - 1, n - 1, grid);
    }
};