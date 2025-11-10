#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=TmhpgXScLyY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=21

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(M * N)
> Space Complexity: O(N)
*/
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i < 0 || j < 0 || matrix[i][j] == 1)
                {
                    temp[j] = 0;
                }
                else if (i == 0 && j == 0)
                {
                    temp[j] = 1;
                }
                else
                {
                    int up = 0, left = 0;
                    if (i > 0)
                    {
                        up = prev[j];
                    }
                    if (j > 0)
                    {
                        left = temp[j - 1];
                    }
                    temp[j] = up + left;
                }
            }
            prev = temp;
        }
        return prev[n - 1];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(M * N)
> Space Complexity: O(M * N)
*/
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

/*
> Time Complexity: O(M * N)
> Space Complexity: O((M - 1) + (N - 1)) + O(M * N)
*/

class Solution
{
public:
    int helper(vector<vector<int>> &matrix, int currRow, int currCol, vector<vector<int>> &dp)
    {
        //* since matrix[0][0] can also be an obstacle in which case we'll never reach it, so we have to check this condition first
        if (currRow < 0 || currCol < 0 || matrix[currRow][currCol] == 1)
        {
            return 0;
        }

        if (currRow == 0 && currCol == 0)
        {
            return 1;
        }

        if (dp[currRow][currCol] != -1)
        {
            return dp[currRow][currCol];
        }

        int up = helper(matrix, currRow - 1, currCol, dp);
        int left = helper(matrix, currRow, currCol - 1, dp);
        return dp[currRow][currCol] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        return helper(matrix, row - 1, col - 1, dp);
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(2^[(M + N) * (M + N)])
> Space Complexity: O((M - 1) + (N - 1))
*/
class Solution
{
public:
    int helper(vector<vector<int>> &matrix, int currRow, int currCol)
    {
        //* since matrix[0][0] can also be an obstacle in which case we'll never reach it, so we have to check this condition first
        if (currRow < 0 || currCol < 0 || matrix[currRow][currCol] == 1)
        {
            return 0;
        }

        if (currRow == 0 && currCol == 0)
        {
            return 1;
        }

        int up = helper(matrix, currRow - 1, currCol);
        int left = helper(matrix, currRow, currCol - 1);
        return up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        return helper(matrix, row - 1, col - 1);
    }
};