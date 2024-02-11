#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Space Optimized Tabulation DP

/* later */

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * M * M * 9)
> Space Complexity: O(N * M * M)
*/

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        //* dp[row][col][col]
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, 0)));

        //* base case
        for (int j1 = 0; j1 < col; j1++)
        {
            for (int j2 = 0; j2 < col; j2++)
            {
                if (j1 == j2)
                {
                    dp[row - 1][j1][j2] = grid[row - 1][j1];
                }
                else
                {
                    dp[row - 1][j1][j2] = grid[row - 1][j1] + grid[row - 1][j2];
                }
            }
        }

        //* explore all paths
        for (int i = row - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < col; j1++)
            {
                for (int j2 = 0; j2 < col; j2++)
                {
                    int maxVal = -1e8;
                    for (int d1 = -1; d1 <= 1; d1++)
                    {
                        for (int d2 = -1; d2 <= 1; d2++)
                        {
                            int value = 0;
                            if (j1 == j2)
                            {
                                value = grid[i][j1];
                            }
                            else
                            {
                                value = grid[i][j1] + grid[i][j2];
                            }
                            if (j1 + d1 >= 0 && j1 + d1 < col && j2 + d2 >= 0 && j2 + d2 < col)
                            {
                                value += dp[i + 1][j1 + d1][j2 + d2];
                            }
                            else
                            {
                                value += -1e8;
                            }
                            maxVal = max(maxVal, value);
                        }
                    }
                    dp[i][j1][j2] = maxVal;
                }
            }
        }

        return dp[0][0][col - 1];
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * M * M * 9)
> Space Complexity: O(N * M * M) + O(N) (auxiliary stack space)
*/

class Solution
{
public:
    int helper(int i, int j1, int j2, int row, int col, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        //* base case (not considering i as i = n - 1 is also destination so it'll be covered there)
        if (j1 < 0 || j2 < 0 || j1 >= col || j2 >= col)
        {
            return -1e8;
        }

        if (dp[i][j1][j2] != -1)
        {
            return dp[i][j1][j2];
        }

        if (i == row - 1)
        {
            //* check if both robots at same cell
            if (j1 == j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1] + grid[i][j2];
            }
        }

        //* explore all paths, for every one move of r1, r2 has 3 moves so total of 9 moves
        int maxVal = -1e8;
        for (int d1 = -1; d1 <= 1; d1++)
        {
            for (int d2 = -1; d2 <= 1; d2++)
            {
                int value = 0;
                if (j1 == j2)
                {
                    value = grid[i][j1];
                }
                else
                {
                    value = grid[i][j1] + grid[i][j2];
                }
                value += helper(i + 1, j1 + d1, j2 + d2, row, col, grid, dp);
                maxVal = max(maxVal, value);
            }
        }
        return dp[i][j1][j2] = maxVal;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        //* dp[row][col][col]
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));

        return helper(0, 0, col - 1, row, col, grid, dp);
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(3^N * 3^N)
> Space Complexity: O(N) (auxiliary stack space)
*/

class Solution
{
public:
    int helper(int i, int j1, int j2, int row, int col, vector<vector<int>> &grid)
    {
        //* base case (not considering i as i = n - 1 is also destination so it'll be covered there)
        if (j1 < 0 || j2 < 0 || j1 >= col || j2 >= col)
        {
            return -1e8;
        }

        if (i == row - 1)
        {
            //* check if both robots at same cell
            if (j1 == j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1] + grid[i][j2];
            }
        }

        //* explore all paths, for every one move of r1, r2 has 3 moves so total of 9 moves
        int maxVal = -1e8;
        for (int d1 = -1; d1 <= 1; d1++)
        {
            for (int d2 = -1; d2 <= 1; d2++)
            {
                int value = 0;
                if (j1 == j2)
                {
                    value = grid[i][j1];
                }
                else
                {
                    value = grid[i][j1] + grid[i][j2];
                }
                value += helper(i + 1, j1 + d1, j2 + d2, row, col, grid);
                maxVal = max(maxVal, value);
            }
        }
        return maxVal;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        return helper(0, 0, col - 1, row, col, grid);
    }
};