#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#include <bits/stdc++.h>

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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
                left += -1e9;
            }
            up += dp[i - 1][j];
            if (j < m - 1)
            {
                right += dp[i - 1][j + 1];
            }
            else
            {
                right += -1e9;
            }

            dp[i][j] = max(left, max(up, right));
        }
    }

    int maxPathSum = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        maxPathSum = max(maxPathSum, dp[n - 1][j]);
    }

    return maxPathSum;
}