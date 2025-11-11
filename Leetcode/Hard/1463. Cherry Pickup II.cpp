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
> Time Complexity: O(N * M * M * 9)
> Space Complexity: O(N * N)
*/

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &matrix)
    {
        //* f(m - 1, n): max cherries collected by 2 robots from (0, 0) & (0, n-1) to last row

        int m = matrix.size();
        int n = matrix[0].size();

        //* 1D DP -> 2 Variables, 2D DP -> 1D Array, 3D DP -> 2D Array for space optimization
        vector<vector<int>> front(n, vector<int>(n, 0));

        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                if (j1 == j2)
                {
                    front[j1][j2] = matrix[m - 1][j1];
                }
                else
                {
                    front[j1][j2] = matrix[m - 1][j1] + matrix[m - 1][j2];
                }
            }
        }

        for (int row = m - 2; row >= 0; row--)
        {
            vector<vector<int>> curr(n, vector<int>(n, 0));
            for (int col1 = 0; col1 < n; col1++)
            {
                for (int col2 = 0; col2 < n; col2++)
                {
                    int maxSum = -1e9;
                    for (int j1 = -1; j1 <= 1; j1++)
                    {
                        for (int j2 = -1; j2 <= 1; j2++)
                        {
                            int tempSum = 0;
                            if (col1 == col2)
                            {
                                tempSum = matrix[row][col1];
                            }
                            else
                            {
                                tempSum = matrix[row][col1] + matrix[row][col2];
                            }

                            if ((col1 + j1) >= 0 && (col2 + j2) >= 0 && (col1 + j1) < n && (col2 + j2) < n)
                            {
                                tempSum += front[col1 + j1][col2 + j2]; //* dp[i + 1] -> front
                            }
                            else
                            {
                                tempSum += -1e9;
                            }

                            maxSum = max(maxSum, tempSum);
                        }
                    }
                    curr[col1][col2] = maxSum; //* dp[i] -> curr
                }
            }
            front = curr;
        }

        return front[0][n - 1]; //* starting point of robots is the answer
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * M * M * 9)
> Space Complexity: O(N * M * M)
*/

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &matrix)
    {
        //* f(m - 1, n): max cherries collected by 2 robots from (0, 0) & (0, n-1) to last row

        int m = matrix.size();
        int n = matrix[0].size();

        //* we have 3 states in recursion, row col1 and col2
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                if (j1 == j2)
                {
                    dp[m - 1][j1][j2] = matrix[m - 1][j1];
                }
                else
                {
                    dp[m - 1][j1][j2] = matrix[m - 1][j1] + matrix[m - 1][j2];
                }
            }
        }

        for (int row = m - 2; row >= 0; row--)
        {
            for (int col1 = 0; col1 < n; col1++)
            {
                for (int col2 = 0; col2 < n; col2++)
                {
                    int maxSum = -1e9;
                    for (int j1 = -1; j1 <= 1; j1++)
                    {
                        for (int j2 = -1; j2 <= 1; j2++)
                        {
                            int tempSum = 0;
                            if (col1 == col2)
                            {
                                tempSum = matrix[row][col1];
                            }
                            else
                            {
                                tempSum = matrix[row][col1] + matrix[row][col2];
                            }

                            if ((col1 + j1) >= 0 && (col2 + j2) >= 0 && (col1 + j1) < n && (col2 + j2) < n)
                            {
                                tempSum += dp[row + 1][col1 + j1][col2 + j2];
                            }
                            else
                            {
                                tempSum += -1e9;
                            }

                            maxSum = max(maxSum, tempSum);
                        }
                    }
                    dp[row][col1][col2] = maxSum;
                }
            }
        }

        return dp[0][0][n - 1]; //* starting point of robots is the answer
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * M * M) * 9 -> We have N * M * M different states (which will be called once then stored in dp array) then for each state we have a loop of size 9
> Space Complexity: O(N * M * M) + O(N) (auxiliary stack space)
*/

class Solution
{
public:
    int helper(vector<vector<int>> &matrix, int row, int col1, int col2, vector<vector<vector<int>>> &dp)
    {
        //* row value will never go below 0, also last row is main base case so it will be covered there
        if (col1 < 0 || col1 >= matrix[0].size() || col2 < 0 || col2 >= matrix[0].size())
        {
            return -1e9;
        }

        if (row == matrix.size() - 1)
        {
            if (col1 == col2)
            {
                return matrix[row][col1];
            }
            else
            {
                return matrix[row][col1] + matrix[row][col2];
            }
        }

        if (dp[row][col1][col2] != -1)
        {
            return dp[row][col1][col2];
        }

        //* for every move of robot 1, robot 2 has 3 moves, so together there are 9 different combo of moves possible
        int maxSum = -1e9;
        for (int j1 = -1; j1 <= 1; j1++)
        {
            for (int j2 = -1; j2 <= 1; j2++)
            {
                if (col1 == col2)
                {
                    maxSum = max(maxSum, matrix[row][col1] + helper(matrix, row + 1, col1 + j1, col2 + j2, dp));
                }
                else
                {
                    maxSum = max(maxSum, matrix[row][col1] + matrix[row][col2] + helper(matrix, row + 1, col1 + j1, col2 + j2, dp));
                }
            }
        }
        return dp[row][col1][col2] = maxSum;
    }

    int cherryPickup(vector<vector<int>> &matrix)
    {
        //* f(m - 1, n): max cherries collected by 2 robots from (0, 0) & (0, n-1) to last row

        int row = matrix.size();
        int col = matrix[0].size();

        //* we have 3 states in recursion, row col1 and col2
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));

        return helper(matrix, 0, 0, col - 1, dp); //* for both the row number remains same, it increases by 1 in every move
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(3^N * 3^N)
> Space Complexity: O(N) -> Auxiliary stack space
*/

class Solution
{
public:
    int helper(vector<vector<int>> &matrix, int row, int col1, int col2)
    {
        //* row value will never go below 0, also last row is main base case so it will be covered there
        if (col1 < 0 || col1 >= matrix[0].size() || col2 < 0 || col2 >= matrix[0].size())
        {
            return -1e9;
        }

        if (row == matrix.size() - 1)
        {
            if (col1 == col2)
            {
                return matrix[row][col1];
            }
            else
            {
                return matrix[row][col1] + matrix[row][col2];
            }
        }

        //* for every move of robot 1, robot 2 has 3 moves, so together there are 9 different combo of moves possible
        vector<int> delta = {-1, 0, 1};
        int maxSum = INT_MIN;
        for (int j1 = 0; j1 < 3; j1++)
        {
            for (int j2 = 0; j2 < 3; j2++)
            {
                if (col1 == col2)
                {
                    maxSum = max(maxSum, matrix[row][col1] + helper(matrix, row + 1, col1 + delta[j1], col2 + delta[j2]));
                }
                else
                {
                    maxSum = max(maxSum, matrix[row][col1] + matrix[row][col2] + helper(matrix, row + 1, col1 + delta[j1], col2 + delta[j2]));
                }
            }
        }
        return maxSum;
    }

    int cherryPickup(vector<vector<int>> &matrix)
    {
        //* f(m - 1, n): max cherries collected by 2 robots from (0, 0) & (0, n-1) to last row

        int row = matrix.size();
        int col = matrix[0].size();
        return helper(matrix, 0, 0, col - 1); //* for both the row number remains same, it increases by 1 in every move
    }
};