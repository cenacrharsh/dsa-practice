#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    long long MOD = 1e9 + 7;
    int dp[51][51][51];
    int helper(int row, int col, int movesLeft, int currRow, int currCol)
    {
        if (currRow < 0 || currRow >= row || currCol < 0 || currCol >= col)
        {
            return 1;
        }

        if (movesLeft <= 0)
        {
            return 0;
        }

        if (dp[currRow][currCol][movesLeft] != -1)
        {
            return dp[currRow][currCol][movesLeft];
        }

        //* up
        int up = helper(row, col, movesLeft - 1, currRow - 1, currCol);

        //* down
        int down = helper(row, col, movesLeft - 1, currRow + 1, currCol);

        //* left
        int left = helper(row, col, movesLeft - 1, currRow, currCol - 1);

        //* right
        int right = helper(row, col, movesLeft - 1, currRow, currCol + 1);

        return dp[currRow][currCol][movesLeft] = ((up % MOD) + (down % MOD) + (left % MOD) + (right % MOD)) % MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        return helper(m, n, maxMove, startRow, startColumn);
    }
};