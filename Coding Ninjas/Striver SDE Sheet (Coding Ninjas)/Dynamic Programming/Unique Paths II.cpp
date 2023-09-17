#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == -1)
            {
                dp[i][j] = 0;
            }
            else if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int up = 0;
                int left = 0;

                if (i > 0)
                {
                    up = dp[i - 1][j] % mod;
                }
                if (j > 0)
                {
                    left = dp[i][j - 1] % mod;
                }
                dp[i][j] = (up + left) % mod;
            }
        }
    }
    return dp[n - 1][m - 1];
}