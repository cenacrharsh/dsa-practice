#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=vRVfmbCFW7Y&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=27

//- f(i, j) -> f(1, 4) -> min number of multiplications required to multipy Matrix 1 to Matrix 4

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N^3)
> Space Complexity: O(N^2))
*/

#include <bits/stdc++.h>
int matrixChainMultiplication(int *arr, int n)
{
    int N = n + 1; //* arr is of size n + 1
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i = 1; i < N; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int minSteps = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int steps = (arr[i - 1] * arr[k] * arr[j]) +
                            dp[i][k] + dp[k + 1][j];
                minSteps = min(minSteps, steps);
            };
            dp[i][j] = minSteps;
        }
    }

    return dp[1][N - 1];
}

//! Memoization DP

/*
> Time Complexity: O(N * N) * O(N) => O(N^3)
> Space Complexity: O(N * N) + O(N)
*/

int helper(int i, int j, int *arr, vector<vector<int>> &dp)
{
    //* base case -> single array
    if (i == j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int minSteps = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] +
                    helper(i, k, arr, dp) + helper(k + 1, j, arr, dp);
        minSteps = min(minSteps, steps);
    }

    return dp[i][j] = minSteps;
}

int matrixChainMultiplication(int *arr, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return helper(1, n, arr, dp); //* arr is of size n + 1
}

//! Recursion -> Top Down Approach

/*
> Time Complexity: Exponential
> Space Complexity: O()
*/

int helper(int i, int j, int *arr)
{
    //* base case -> single array
    if (i == j)
    {
        return 0;
    }

    int minSteps = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] +
                    helper(i, k, arr) + helper(k + 1, j, arr);
        minSteps = min(minSteps, steps);
    }

    return minSteps;
}

int matrixChainMultiplication(int *arr, int n)
{
    return helper(1, n, arr); //* arr is of size n + 1
}