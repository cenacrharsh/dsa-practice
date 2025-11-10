#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(N * M)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> prev(n, 0);
        for (int i = 0; i < n; i++)
        {
            prev[i] = matrix[0][i];
        }

        for (int currRow = 1; currRow < m; currRow++)
        {
            vector<int> temp(n, 0);
            for (int currCol = 0; currCol < n; currCol++)
            {
                int up = currRow > 0 ? prev[currCol] : 1e9;
                int upLeft = (currRow > 0 && currCol > 0) ? prev[currCol - 1] : 1e9;
                int upRight = (currRow > 0 && currCol < n - 1) ? prev[currCol + 1] : 1e9;

                int minPathSum = matrix[currRow][currCol] + min(up, min(upLeft, upRight));
                temp[currCol] = minPathSum;
            }
            prev = temp;
        }

        int minSum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            minSum = min(minSum, prev[i]);
        }
        return minSum;
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
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            dp[0][i] = matrix[0][i];
        }

        for (int currRow = 1; currRow < m; currRow++)
        {
            for (int currCol = 0; currCol < n; currCol++)
            {
                int up = currRow > 0 ? dp[currRow - 1][currCol] : 1e9;
                int upLeft = (currRow > 0 && currCol > 0) ? dp[currRow - 1][currCol - 1] : 1e9;
                int upRight = (currRow > 0 && currCol < n - 1) ? dp[currRow - 1][currCol + 1] : 1e9;

                int minPathSum = matrix[currRow][currCol] + min(up, min(upLeft, upRight));
                dp[currRow][currCol] = minPathSum;
            }
        }

        int minSum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            minSum = min(minSum, dp[m - 1][i]);
        }
        return minSum;
    }
};

//! Memoization DP
/*
> Time Complexity: O(N * M)
> Space Complexity: O(N * M) + O(N * M)
*/

class Solution
{
public:
    int helper(vector<vector<int>> &matrix, int currRow, int currCol, vector<vector<int>> &dp)
    {
        if (currRow == 0 && currCol >= 0 && currCol < matrix[0].size())
        {
            return matrix[currRow][currCol];
        }

        if (currRow < 0 || currCol < 0 || currCol >= matrix[0].size())
        {
            return INT_MAX;
        }

        if (dp[currRow][currCol] != -1)
        {
            return dp[currRow][currCol];
        }

        int up = helper(matrix, currRow - 1, currCol, dp);
        int upLeft = helper(matrix, currRow - 1, currCol - 1, dp);
        int upRight = helper(matrix, currRow - 1, currCol + 1, dp);

        int minPathSum;
        if (up == INT_MAX && upLeft == INT_MAX && upRight == INT_MAX)
        {
            minPathSum = INT_MAX;
        }
        else
        {
            minPathSum = matrix[currRow][currCol] + min(up, min(upLeft, upRight));
        }
        return dp[currRow][currCol] = minPathSum;
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int minSum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            minSum = min(minSum, helper(matrix, m - 1, i, dp));
        }
        return minSum;
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(3^N) -> 3 Choices and Max Depth for Recursion is N
> Space Complexity: O(N) -> Recursion Depth
*/

class Solution
{
public:
    int helper(vector<vector<int>> &matrix, int currRow, int currCol)
    {
        if (currRow == 0 && currCol >= 0 && currCol < matrix[0].size())
        {
            return matrix[currRow][currCol];
        }

        if (currRow < 0 || currCol < 0 || currCol >= matrix[0].size())
        {
            return INT_MAX;
        }

        int up = helper(matrix, currRow - 1, currCol);
        int upLeft = helper(matrix, currRow - 1, currCol - 1);
        int upRight = helper(matrix, currRow - 1, currCol + 1);

        if (up == INT_MAX && upLeft == INT_MAX && upRight == INT_MAX)
        {
            return INT_MAX;
        }
        else
        {
            return matrix[currRow][currCol] + min(up, min(upLeft, upRight));
        }
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int minSum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            minSum = min(minSum, helper(matrix, m - 1, i));
        }
        return minSum;
    }
};