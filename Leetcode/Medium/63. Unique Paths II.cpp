#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=TmhpgXScLyY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=21

//! Space Optimized Tabulation DP
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    curr[j] = 0;
                else if (i == 0 && j == 0)
                    curr[j] = 1;
                else
                {
                    int up = 0;
                    int left = 0;
                    if (i > 0)
                    {
                        up = prev[j];
                    }
                    if (j > 0)
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
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else
                {
                    int up = 0;
                    int left = 0;
                    if (i > 0)
                    {
                        up = dp[i - 1][j];
                    }
                    if (j > 0)
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
class Solution
{
public:
    int helper(int row, int col, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        // since matrix[0][0] can also be an obstacle in which case we'll never reach it, so we have to check this condition first
        if (row >= 0 && col >= 0 && obstacleGrid[row][col] == 1)
            return 0;
        if (row == 0 && col == 0)
            return 1;
        if (row < 0 || col < 0)
            return 0;

        if (dp[row][col] != -1)
            return dp[row][col];

        int up = helper(row - 1, col, obstacleGrid, dp);
        int left = helper(row, col - 1, obstacleGrid, dp);

        return dp[row][col] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, obstacleGrid, dp);
    }
};

//! Recursion -> Top Down Approach
class Solution
{
public:
    int helper(int row, int col, vector<vector<int>> &obstacleGrid)
    {
        //* since matrix[0][0] can also be an obstacle in which case we'll never reach it, so we have to check this condition first
        if (row >= 0 && col >= 0 && obstacleGrid[row][col] == 1)
            return 0;
        if (row == 0 && col == 0)
            return 1;
        if (row < 0 || col < 0)
            return 0;

        int up = helper(row - 1, col, obstacleGrid);
        int left = helper(row, col - 1, obstacleGrid);

        return up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return helper(m - 1, n - 1, obstacleGrid);
    }
};