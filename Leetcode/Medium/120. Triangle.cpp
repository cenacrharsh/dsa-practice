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
> Time Complexity: O(N * N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        //* f(0, 0): Min path from (0, 0) to last row
        //* Tabulation and Recursion are always opposite of each other, we fill the base case of recursion and then construct the sol. from there, here from (m - 1) to 0, even the double for loop will run from (m - 1) to 0 since in recursion it went from 0->(m - 1)

        int m = triangle.size(); //* max col = no. of rows

        vector<int> front(m, 0);
        for (int j = 0; j < m; j++)
        {
            front[j] = triangle[m - 1][j];
        }

        for (int currRow = m - 2; currRow >= 0; currRow--)
        {
            vector<int> temp(m, 0);
            for (int currCol = currRow; currCol >= 0; currCol--)
            {
                int down = (currRow < m - 1) ? front[currCol] : 1e9;
                int downRight = (currRow < m - 1 && currCol < m - 1) ? front[currCol + 1] : 1e9;

                if (down == 1e9 && downRight == 1e9)
                {
                    temp[currCol] = 1e9;
                }
                else
                {
                    temp[currCol] = triangle[currRow][currCol] + min(down, downRight);
                }
            }
            front = temp;
        }

        return front[0];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * N)
> Space Complexity: O(N * N)
*/

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        //* f(0, 0): Min path from (0, 0) to last row
        //* Tabulation and Recursion are always opposite of each other, we fill the base case of recursion and then construct the sol. from there, here from (m - 1) to 0, even the double for loop will run from (m - 1) to 0 since in recursion it went from 0->(m - 1)

        int m = triangle.size(); //* max col = no. of rows

        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
        {
            dp[m - 1][j] = triangle[m - 1][j];
        }

        for (int currRow = m - 2; currRow >= 0; currRow--)
        {
            for (int currCol = currRow; currCol >= 0; currCol--)
            {
                int down = (currRow < m - 1) ? dp[currRow + 1][currCol] : 1e9;
                int downRight = (currRow < m - 1 && currCol < m - 1) ? dp[currRow + 1][currCol + 1] : 1e9;

                if (down == 1e9 && downRight == 1e9)
                {
                    dp[currRow][currCol] = 1e9;
                }
                else
                {
                    dp[currRow][currCol] = triangle[currRow][currCol] + min(down, downRight);
                }
            }
        }

        return dp[0][0];
    }
};

//! Memoization DP
/*
> Time Complexity: O(N * N)
> Space Complexity: O(N) + O(N * N)
*/

class Solution
{
public:
    int helper(vector<vector<int>> &triangle, int currRow, int currCol, vector<vector<int>> &dp)
    {
        if (currRow == triangle.size() - 1 && currCol >= 0 && currCol < triangle.size())
        {
            return triangle[currRow][currCol];
        }

        if (currRow >= triangle.size() || currCol >= triangle.size())
        {
            return 1e9;
        }

        if (dp[currRow][currCol] != -1)
        {
            return dp[currRow][currCol];
        }

        int down = helper(triangle, currRow + 1, currCol, dp);
        int downRight = helper(triangle, currRow + 1, currCol + 1, dp);

        if (down == 1e9 && downRight == 1e9)
        {
            return dp[currRow][currCol] = 1e9;
        }
        else
        {
            return dp[currRow][currCol] = triangle[currRow][currCol] + min(down, downRight);
        }
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        //* f(0, 0): Min path from (0, 0) to last row

        int m = triangle.size(); //* max col = no. of rows

        vector<vector<int>> dp(m, vector<int>(m, -1));

        return helper(triangle, 0, 0, dp); //* easier to go from (0, 0) to last row than from entire last row to (0, 0)
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(2^(1 + 2 + 3 + 4...N))
> Space Complexity: O(N)
*/

class Solution
{
public:
    int helper(vector<vector<int>> &triangle, int currRow, int currCol)
    {
        //* f(0, 0): Min path from (0, 0) to last row

        if (currRow == triangle.size() - 1 && currCol >= 0 && currCol < triangle.size())
        {
            return triangle[currRow][currCol];
        }

        if (currRow >= triangle.size() || currCol >= triangle.size())
        {
            return 1e9;
        }

        int down = helper(triangle, currRow + 1, currCol);
        int downRight = helper(triangle, currRow + 1, currCol + 1);

        if (down == 1e9 && downRight == 1e9)
        {
            return 1e9;
        }
        else
        {
            return triangle[currRow][currCol] + min(down, downRight);
        }
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size(); //* max col = no. of rows

        return helper(triangle, 0, 0); //* easier to go from (0, 0) to last row than from entire last row to (0, 0)
    }
};

//----- or ------

class Solution
{
public:
    int helper(vector<vector<int>> &triangle, int currRow, int currCol)
    {
        if (currRow == 0 && currCol == 0)
        {
            return triangle[currRow][currCol];
        }

        if (currRow < 0 || currCol < 0)
        {
            return 1e9;
        }

        int up = helper(triangle, currRow - 1, currCol);
        int upLeft = helper(triangle, currRow - 1, currCol - 1);

        if (up == 1e9 && upLeft == 1e9)
        {
            return 1e9;
        }
        else
        {
            return triangle[currRow][currCol] + min(up, upLeft);
        }
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size(); //* max col = no. of rows

        int minSum = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            minSum = min(minSum, helper(triangle, m - 1, i));
        }
        return minSum;
    }
};