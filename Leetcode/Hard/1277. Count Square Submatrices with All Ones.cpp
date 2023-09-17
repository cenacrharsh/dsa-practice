#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=auS1fynpnjo&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=30

//- f(i, j) -> how many squares are there with their right bottom at (i, j)

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = matrix[i][0];
        for (int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j];

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j],
                                    min(dp[i - 1][j - 1], dp[i][j - 1]));
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sum += dp[i][j];
            }
        }

        return sum;
    }
};