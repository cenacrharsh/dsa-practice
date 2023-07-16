#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#include <bits/stdc++.h>
int minSumPath(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[0][0] = grid[0][0];
            }
            else
            {
                int up = grid[i][j];
                int left = grid[i][j];

                if (i > 0)
                {
                    up += dp[i - 1][j];
                }
                else
                {
                    up += 1e9;
                }

                if (j > 0)
                {
                    left += dp[i][j - 1];
                }
                else
                {
                    left += 1e9;
                }

                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[row - 1][col - 1];
}