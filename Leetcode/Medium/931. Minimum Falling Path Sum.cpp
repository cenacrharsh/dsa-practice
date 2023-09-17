#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=N_aJ5qQbYA0&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=8

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(N * M) + O(M)
> Space Complexity: O(N) + O(M)
*/

// f(i, j) => min sum req to reach (i, j) from any cell in 1st row
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        for (int col = 0; col < n; col++)
        {
            prev[col] = matrix[0][col];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int left = matrix[i][j];
                int up = matrix[i][j];
                int right = matrix[i][j];

                if (j > 0)
                {
                    left += prev[j - 1];
                }
                else
                {
                    left += 1e9;
                }
                up += prev[j];
                if (j < n - 1)
                {
                    right += prev[j + 1];
                }
                else
                {
                    right += 1e9;
                }

                curr[j] = min(left, min(up, right));
            }
            prev = curr;
        }

        int minPathSum = INT_MAX;
        for (int col = 0; col < n; col++)
        {
            minPathSum = min(minPathSum, prev[col]);
        }
        return minPathSum;
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * M) + O(M)
> Space Complexity: O(N * M)
*/

// f(i, j) => min sum req to reach (i, j) from any cell in 1st row
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int col = 0; col < n; col++)
        {
            dp[0][col] = matrix[0][col];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int left = matrix[i][j];
                int up = matrix[i][j];
                int right = matrix[i][j];

                if (j > 0)
                {
                    left += dp[i - 1][j - 1];
                }
                else
                {
                    left += 1e9;
                }
                up += dp[i - 1][j];
                if (j < n - 1)
                {
                    right += dp[i - 1][j + 1];
                }
                else
                {
                    right += 1e9;
                }

                dp[i][j] = min(left, min(up, right));
            }
        }

        int minPathSum = INT_MAX;
        for (int col = 0; col < n; col++)
        {
            minPathSum = min(minPathSum, dp[n - 1][col]);
        }
        return minPathSum;
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * M)
> Space Complexity: O(N * M) + O(N) -> Recursive stack space
*/

// f(i, j) => min sum req to reach (i, j) from any cell in 1st row
class Solution
{
public:
    int helper(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        int n = matrix.size();
        if (col < 0 || col >= n)
        {
            return 1e9;
        }
        if (row == 0)
        {
            return matrix[row][col];
        }

        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }

        int left = matrix[row][col] + helper(row - 1, col - 1, matrix, dp);
        int up = matrix[row][col] + helper(row - 1, col, matrix, dp);
        int right = matrix[row][col] + helper(row - 1, col + 1, matrix, dp);

        return dp[row][col] = min(left, min(up, right));
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int minPathSum = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            int currPathSum = helper(n - 1, i, matrix, dp);
            minPathSum = min(minPathSum, currPathSum);
        }
        return minPathSum;
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(3^N)
> Space Complexity: O(N) -> Recursive stack space
*/

// f(i, j) => min sum req to reach (i, j) from any cell in 1st row
class Solution
{
public:
    int helper(int row, int col, vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (col < 0 || col >= n)
        {
            return 1e9;
        }
        if (row == 0)
        {
            return matrix[row][col];
        }

        int left = matrix[row][col] + helper(row - 1, col - 1, matrix);
        int up = matrix[row][col] + helper(row - 1, col, matrix);
        int right = matrix[row][col] + helper(row - 1, col + 1, matrix);

        return min(left, min(up, right));
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int minPathSum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int currPathSum = helper(n - 1, i, matrix);
            minPathSum = min(minPathSum, currPathSum);
        }
        return minPathSum;
    }
};