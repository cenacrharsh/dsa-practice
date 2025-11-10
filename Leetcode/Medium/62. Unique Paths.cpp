#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

/*-------------------------------------------------------------------------------------------------------*/

// # Tutorial: https://www.youtube.com/watch?v=sdE0A2Oxofw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=25

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(M * N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        //* f(m - 1, n - 1): No. of unique ways to go from 0->(m - 1, n - 1)

        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    temp[j] = 1;
                }
                else
                {
                    int up = i > 0 ? prev[j] : 0;
                    int left = j > 0 ? temp[j - 1] : 0;
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
> Space Complexity: O(M + N)
*/

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        //* f(m - 1, n - 1): No. of unique ways to go from 0->(m - 1, n - 1)

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int up = i > 0 ? dp[i - 1][j] : 0;
                    int left = j > 0 ? dp[i][j - 1] : 0;
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
> Space Complexity: O((M - 1) + (N - 1)) + O(M * N) => recursive stack space + DP vector
*/

class Solution
{
public:
    int helper(int currRow, int currCol, vector<vector<int>> &dp)
    {
        if (currRow == 0 && currCol == 0)
        {
            return 1;
        }

        if (currRow < 0 || currCol < 0)
        {
            return 0;
        }

        if (dp[currRow][currCol] != -1)
        {
            return dp[currRow][currCol];
        }

        return dp[currRow][currCol] = helper(currRow, currCol - 1, dp) + helper(currRow - 1, currCol, dp);
    }

    int uniquePaths(int m, int n)
    {
        //* f(m - 1, n - 1): No. of unique ways to go from 0->(m - 1, n - 1)

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, dp);
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(2^(M * N))
> Space Complexity: O((M - 1) + (N - 1)) => Path length
*/
class Solution
{
public:
    int helper(int currRow, int currCol)
    {
        if (currRow == 0 && currCol == 0)
        {
            return 1;
        }

        if (currRow < 0 || currCol < 0)
        {
            return 0;
        }

        int left = helper(currRow, currCol - 1);
        int up = helper(currRow - 1, currCol);

        return left + up;
    }

    int uniquePaths(int m, int n)
    {
        //* f(m - 1, n - 1): No. of unique ways to go from 0->(m - 1, n - 1)

        return helper(m - 1, n - 1);
    }
};
